package controller

import (
	"bufio"
	"database/sql"
	srv "http-comp/go-net/service"
	"net"
	"net/http"
	"regexp"
	"strings"
)

func HandleConnection(conn net.Conn, db *sql.DB) {
	reader := bufio.NewReader(conn)

	request, err := http.ReadRequest(reader)

	if err != nil {
		srv.Build400Response(conn)
		return
	}

	defer conn.Close()

	path := request.URL.Path

	if path == "/user" {
		UserHandler(conn, request, db)
	} else if regexp.MustCompile(`/user/(\d+)$`).MatchString(path) {
		id := strings.TrimPrefix(path, "/user/")
		UserByIdHandler(conn, request, db, id)
	} else if regexp.MustCompile(`/user/(\d+)/address$`).MatchString(path) {
		id := strings.TrimSuffix(strings.TrimPrefix(path, "/user/"), "/address")
		AddressByUserIdHandler(conn, request, db, id)
	} else {
		srv.Build404Response(conn)
	}
}

func UserHandler(conn net.Conn, request *http.Request, db *sql.DB) {
	if request.Method == "POST" {
		srv.PostUser(conn, request, db)
	} else {
		srv.Build404Response(conn)
	}
}

func UserByIdHandler(conn net.Conn, request *http.Request, db *sql.DB, id string) {
	if request.Method == "GET" {
		srv.GetUserById(conn, db, id)
	} else if request.Method == "PUT" {
		// srv.PostUser(conn, request, db)
	} else {
		srv.Build405Response(conn)
	}
}

func AddressByUserIdHandler(conn net.Conn, request *http.Request, db *sql.DB, id string) {
	if request.Method == "GET" {
		srv.GetAddressesByUserId(conn, db, id)
	} else if request.Method == "POST" {
		// srv.PostAddress(conn, request, db, id)
	} else {
		srv.Build405Response(conn)
	}
}
