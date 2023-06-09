package main

import (
	"database/sql"
	"fmt"
	ctr "http-comp/go-net/controller"
	"log"
	"net"
	"time"

	"github.com/go-sql-driver/mysql"
)

func main() {
	cfg := mysql.Config{
		User:   "root",
		Passwd: "change-me",
		Net:    "tcp",
		Addr:   "localhost:3306",
		DBName: "test",
	}
	db, err := sql.Open("mysql", cfg.FormatDSN())
	if err != nil {
		log.Println("SQL fail: ", err)
		return
	}
	pingErr := db.Ping()
	if pingErr != nil {
		log.Println("Database connection fail: ", err)
		return
	}
	db.SetConnMaxLifetime(time.Minute * 3)
	db.SetMaxOpenConns(10)
	db.SetMaxIdleConns(10)

	listener, err := net.Listen("tcp", ":8080")
	if err != nil {
		log.Println("Listener start fail: ", err)
		return
	}

	fmt.Println("Server listening on port 8080")

	defer listener.Close()

	for {
		conn, err := listener.Accept()

		if err != nil {
			log.Println("Listener connection fail: ", err)
		}

		go ctr.HandleConnection(conn, db)
	}
}
