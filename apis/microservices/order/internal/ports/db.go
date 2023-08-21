package ports

import "github.com/agusespa/learn/api/microservices/order/internal/application/domain"

type DBPort interface {
	Get(id string) (domain.Order, error)
	Save(*domain.Order) error
}
