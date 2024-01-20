package server

import (
	"log"
	controller "logger/cmd/controller"
	"net/http"
)

func main() {
	handler := controller.GetHandler()

	err := http.ListenAndServe(":8080", handler)
	if err != nil {
		log.Fatal(err)
	}
}
