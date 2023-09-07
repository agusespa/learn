package domain

type Order struct {
	ID         int64       `json:"id"`
	CustomerID int64       `json:"customer_id"`
	Status     string      `json:"status"`
	OrderItems []OrderItem `json:"order_items"`
	CreatedAt  int64       `json:"created_at"`
}

type OrderItem struct {
	ID       int64   `json:"id" db:"item_id"`
	SKU      string  `json:"product_code" db:"sku"`
	Price    float32 `json:"price" db:"price"`
	Quantity int32   `json:"quantity" db:"quantity"`
}

func NewOrder(customerId int64, orderItems []OrderItem) Order {
	return Order{
		CustomerID: customerId,
		Status:     "Pending",
		OrderItems: orderItems,
	}
}

func (o *Order) TotalPrice() float32 {
	var totalPrice float32
	for _, orderItem := range o.OrderItems {
		totalPrice += orderItem.Price * float32(orderItem.Quantity)
	}
	return totalPrice
}
