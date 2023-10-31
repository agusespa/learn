package api

type UserRequest struct {
	Email    string `json:"email"`
	Username string `json:"username,omitempty"`
}

type APIUser struct {
	UserId   int    `json:"userID"`
	Email    string `json:"email"`
	Username string `json:"username,omitempty"`
}

type AddressRequest struct {
	Street string `json:"street"`
	Number int    `json:"number"`
	City   string `json:"city"`
}

type Address struct {
	AddressId int    `json:"addressID"`
	Street    string `json:"street"`
	Number    int    `json:"number"`
	City      string `json:"city"`
	UserId    int    `json:"-"`
}
