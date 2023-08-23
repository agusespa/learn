package ports

import "github.com/agusespa/learn/api/microservices/go-ecom/order/internal/application/domain"

type APIPort interface {
	PlaceOrder(order domain.Order) (domain.Order, error)
}
