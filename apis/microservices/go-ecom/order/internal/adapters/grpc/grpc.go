package grpc

import (
	"context"

	"github.com/agusespa/learn/api/microservices/go-ecom/order/internal/adapters/db"
	"github.com/agusespa/learn/api/microservices/go-ecom/order/internal/application/domain"
)

func (a db.Adapter) Create(ctx context.Context, request *order.CreateOrderRequest) {
	var orderItems []domain.OrderItem
	for _, orderItem := range request.OrderItems {
		orderItems = append(orderItems, domain.OrderItem{
			ProductCode: orderItem.ProductCode,
			UnitPrice:   orderItem.UnitPrice,
			Quantity:    orderItem.Quantity,
		})
	}
	newOrder := domain.NewOrder(request.UserId, orderItems)
	result, err := a.api.PlaceOrder(newOrder)
	if err != nil {
		return nil, err
	}
	return &order.CreateOrderResponse{OrderId: result.ID}, nil
}
