package main

import (
	"fmt"
	"net/http"
	"os"
	"time"
)

func timeHandler(w http.ResponseWriter, r *http.Request) {
	currentTime := time.Now().Format(time.RFC3339)
	fmt.Fprintf(w, "%s", currentTime)
}

func main() {
	http.HandleFunc("/", timeHandler)

	port := os.Getenv("PORT")
	if port == "" {
		port = "3030"
	}

	fmt.Printf("Starting server on port %s...\n", port)
	err := http.ListenAndServe(fmt.Sprintf(":%s", port), nil)
	if err != nil {
		fmt.Printf("Error starting server: %s\n", err)
	}
}
