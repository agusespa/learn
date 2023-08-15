# syntax=docker/dockerfile:1

FROM golang:1.20

WORKDIR /app

COPY go.mod ./
RUN go mod download

COPY *.go ./

RUN CGO_ENABLED=0 GOOS=linux go build -o /go-api

EXPOSE 3000

CMD ["/go-api"]
