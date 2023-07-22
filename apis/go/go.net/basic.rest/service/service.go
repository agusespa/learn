package service

import (
	"database/sql"
	"encoding/json"
	"net"
	"net/http"

	mdl "go.net/basic.rest/models"
)

func PostUser(conn net.Conn, request *http.Request, db *sql.DB) {
	decoder := json.NewDecoder(request.Body)
	var uP mdl.UserPayload
	err := decoder.Decode(&uP)
	if err != nil {
		Build500Response(conn)
	}

	res, err := db.Exec("INSERT INTO users (email, username) VALUES (?,?)", uP.Email, uP.Username)
	if err != nil {
		Build500Response(conn)
		return
	}

	id, postErr := res.LastInsertId()
	if postErr != nil {
		Build500Response(conn)
		return
	}

	row := db.QueryRow("SELECT * FROM users WHERE user_id = ?", id)

	var u mdl.User
	// handle null values in database
	scanErr := row.Scan(&u.UserId, &u.Username, &u.Email)
	if scanErr != nil {
		Build500Response(conn)
		return
	}

	bytes, err := json.Marshal(u)
	if err != nil {
		Build500Response(conn)
		return
	}
	payload := string(bytes)

	Build201Response(conn, payload)
}

func GetUserById(conn net.Conn, db *sql.DB, id string) {
	row := db.QueryRow("SELECT * FROM users WHERE user_id = ?", id)

	var u mdl.User
	// handle null values in database
	err := row.Scan(&u.UserId, &u.Username, &u.Email)
	if err != nil {
		Build500Response(conn)
		return
	}

	bytes, err := json.Marshal(u)
	if err != nil {
		Build500Response(conn)
		return
	}
	payload := string(bytes)

	Build200Response(conn, payload)
}

func GetAddressesByUserId(conn net.Conn, db *sql.DB, id string) {
	addresses, err := db.Query("SELECT * FROM addresses WHERE user_id = ?", id)
	if err != nil {
		Build500Response(conn)
		return
	}

	defer addresses.Close()

	var addrArr []mdl.Address

	var a mdl.Address

	for addresses.Next() {
		err := addresses.Scan(&a.AddressId, &a.Street, &a.Number, &a.City, &a.UserId)
		if err != nil {
			Build500Response(conn)
			return
		}
		addrArr = append(addrArr, a)
	}

	bytes, err := json.Marshal(addrArr)
	if err != nil {
		Build500Response(conn)
		return
	}
	payload := string(bytes)

	Build200Response(conn, payload)
}
