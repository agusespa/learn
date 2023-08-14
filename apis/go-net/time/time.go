package timeServer

import (
	"fmt"
	"net/http"
	"os"
	"time"
)

func timeHandler(w http.ResponseWriter, r *http.Request) {
	currentTime := time.Now().Format(time.RFC1123)
	fmt.Fprintf(w, "Current time: %s", currentTime)
}

func main() {
	port := os.Getenv("PORT")
	if port == "" {
		port = "3000"
	}

	http.HandleFunc("/time", timeHandler)

	fmt.Printf("Server is listening on port %s...\n", port)
	http.ListenAndServe(":"+port, nil)
}
