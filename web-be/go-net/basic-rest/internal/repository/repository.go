package repository

import (
	"basic-rest/internal/api"
	"database/sql"
)

type Repository struct {
	db *sql.DB
}

func NewRepository(db *sql.DB) *Repository {
	return &Repository{db: db}
}

type DBUser struct {
	UserId   int    `db:"user_id"`
	Email    string `db:"email"`
	Username string `db:"username"`
}

type DBAddress struct {
	AddressId int    `db:"address_id"`
	Street    string `db:"street"`
	Number    int    `db:"number"`
	City      string `db:"city"`
	UserId    int    `db:"user_id"`
}

func (repo *Repository) PostUser(userRequest api.UserRequest) (DBUser, error) {
	res, err := repo.db.Exec("INSERT INTO users (email, username) VALUES (?,?)", userRequest.Email, userRequest.Username)
	if err != nil {
		return DBUser{}, err
	}

	id, postErr := res.LastInsertId()
	if postErr != nil {
		return DBUser{}, err
	}

	row := repo.db.QueryRow("SELECT * FROM users WHERE user_id = ?", id)

	var newUser DBUser
	// handle null values in database
	scanErr := row.Scan(&newUser.UserId, &newUser.Username, &newUser.Email)
	if scanErr != nil {
		return DBUser{}, err
	}

	return newUser, nil
}

func (repo *Repository) GetUserById(id string) (DBUser, error) {
	row := repo.db.QueryRow("SELECT * FROM users WHERE user_id = ?", id)

	var user DBUser
	// handle null values in database
	err := row.Scan(&user.UserId, &user.Username, &user.Email)
	if err != nil {
		return DBUser{}, err
	}

	return user, nil
}

func (repo *Repository) GetAddressesByUserId(id string) ([]DBAddress, error) {
	addr, err := repo.db.Query("SELECT * FROM addresses WHERE user_id = ?", id)
	if err != nil {
		return []DBAddress{}, err
	}

	defer addr.Close()

	var addresses []DBAddress

	var address DBAddress

	for addr.Next() {
		err := addr.Scan(&address.AddressId, &address.Street, &address.Number, &address.City, &address.UserId)
		if err != nil {
			return []DBAddress{}, err
		}
		addresses = append(addresses, address)
	}

	return addresses, nil
}
