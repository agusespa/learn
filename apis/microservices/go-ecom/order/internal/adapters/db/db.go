package db

import (
	"database/sql"
	"fmt"
	"log"
	"os"

	domain "github.com/agusespa/learn/api/microservices/go-ecom/order/internal/application/domain"
	"github.com/go-sql-driver/mysql"
)

type Adapter struct {
	db *sql.DB
}

type OrderEntity struct {
	ID         int64  `db:"order_id"`
	CustomerID int64  `db:"customer_id"`
	Status     string `db:"status"`
	CreatedAt  int64  `db:"created_at"`
}

func NewAdapter(dataSourceUrl string) (*Adapter, error) {
	cfg := mysql.Config{
		User:   os.Getenv("DBUSER"),
		Passwd: os.Getenv("DBPASS"),
		Net:    "tcp",
		Addr:   "127.0.0.1:3306",
		DBName: "databasename",
	}

	db, err := sql.Open("mysql", cfg.FormatDSN())
	if err != nil {
		log.Fatalf("Error opening database connection: %v", err)
	}

	pingErr := db.Ping()
	if pingErr != nil {
		log.Fatalf("Error pinging database: %v", pingErr)
	}

	return &Adapter{db: db}, nil
}

func (a Adapter) Get(id string) (domain.Order, error) {
	var orderEntity OrderEntity
	row := a.db.QueryRow("SELECT * FROM orders WHERE order_id = ?", id)
	if err := row.Scan(&orderEntity.ID, &orderEntity.CustomerID, &orderEntity.Status, &orderEntity.CreatedAt); err != nil {
		if err == sql.ErrNoRows {
			return domain.Order{}, fmt.Errorf("no order with id %s", id)
		}
		return domain.Order{}, fmt.Errorf("%s: %v", id, err)
	}

	var orderItems []domain.OrderItem
	rows, err := a.db.Query("SELECT * FROM items WHERE order_id = ?", id)
	if err != nil {
		return domain.Order{}, fmt.Errorf("items by order %s: %v", id, err)
	}
	defer rows.Close()

	for rows.Next() {
		var orderItem domain.OrderItem

		if err := rows.Scan(&orderItem.ID, &orderItem.ProductCode, &orderItem.UnitPrice, &orderItem.Quantity); err != nil {
			return domain.Order{}, fmt.Errorf("items by order %s: %v", id, err)
		}
		orderItems = append(orderItems, orderItem)
	}

	order := domain.Order{
		ID:         int64(orderEntity.ID),
		CustomerID: orderEntity.CustomerID,
		Status:     orderEntity.Status,
		OrderItems: orderItems,
		CreatedAt:  orderEntity.CreatedAt,
	}
	return order, nil
}
