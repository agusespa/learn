package controller

import (
	"basic-rest/internal/api"
	"basic-rest/internal/repository"
	"bufio"
	"encoding/json"
	"net"
	"net/http"
	"regexp"
	"strings"
)

type App struct {
	Repository *repository.Repository
}

func (app *App) HandleConnection(conn net.Conn) {
	reader := bufio.NewReader(conn)

	request, err := http.ReadRequest(reader)

	if err != nil {
		Build400Response(conn)
		return
	}

	defer conn.Close()

	path := request.URL.Path

	if path == "/user" {
		app.UserHandler(conn, request)
	} else if regexp.MustCompile(`/user/(\d+)$`).MatchString(path) {
		id := strings.TrimPrefix(path, "/user/")
		app.UserByIdHandler(conn, request, id)
	} else if regexp.MustCompile(`/user/(\d+)/address$`).MatchString(path) {
		id := strings.TrimSuffix(strings.TrimPrefix(path, "/user/"), "/address")
		app.AddressByUserIdHandler(conn, request, id)
	} else {
		Build404Response(conn)
	}
}

func (app *App) UserHandler(conn net.Conn, request *http.Request) {
	decoder := json.NewDecoder(request.Body)
	var userReq api.UserRequest
	err := decoder.Decode(&userReq)
	if err != nil {
		Build500Response(conn)
	}

	if request.Method == "POST" {
		// app.Repository.PostUser(userReq)

	} else {
		Build404Response(conn)
	}
}

func (app *App) UserByIdHandler(conn net.Conn, request *http.Request, id string) {
	if request.Method == "GET" {
		user, err := app.Repository.GetUserById(id)
		if err != nil {
			Build500Response(conn)
			return
		}
		userResponse, err := json.Marshal(user)
		if err != nil {
			Build500Response(conn)
			return
		}
		payload := string(userResponse)
		Build200Response(conn, payload)

	} else if request.Method == "PUT" {
		// srv.PostUser(conn, request, db)

	} else {
		Build405Response(conn)
	}
}

func (app *App) AddressByUserIdHandler(conn net.Conn, request *http.Request, id string) {
	if request.Method == "GET" {
		// addr, err := app.Repository.GetAddressesByUserId(id)

	} else if request.Method == "POST" {
		// srv.PostAddress(conn, request, db, id)

	} else {
		Build405Response(conn)
	}
}
