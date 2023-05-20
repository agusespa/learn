package models

type UserPayload struct {
	Email    string `json:"email" db:"email"`
	Username string `json:"username,omitempty" db:"username"`
}

type User struct {
	UserId   int    `json:"userID" db:"user_id"`
	Email    string `json:"email" db:"email"`
	Username string `json:"username,omitempty" db:"username"`
}

type AddressPayload struct {
	Street string `json:"street" db:"street"`
	Number int    `json:"number" db:"number"`
	City   string `json:"city" db:"city"`
}

type Address struct {
	AddressId int    `json:"addressID" db:"address_id"`
	Street    string `json:"street" db:"street"`
	Number    int    `json:"number" db:"number"`
	City      string `json:"city" db:"city"`
	UserId    int    `json:"-" db:"user_id"`
}
