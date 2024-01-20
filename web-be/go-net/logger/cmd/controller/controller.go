package controller

import (
	service "logger/cmd/service"
	"net/http"
)

func GetHandler() *http.ServeMux {
	mux := http.NewServeMux()

	mux.HandleFunc("/", handleLog)

	return mux
}

func handleLog(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		service.HandleGetLog(w, r)
	} else if r.Method == "POST" {
		service.HandlePostLog(w, r)
	}
}
