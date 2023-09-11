package ports

import "order/internal/application/domain"

type DBPort interface {
	Get(int64) (*domain.Order, error)
	Save(*domain.Order) (*domain.Order, error)
}
