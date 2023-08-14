FROM golang:1.17-alpine

WORKDIR /app

COPY time.go .

RUN go build -o app

EXPOSE 3000

CMD ["./app"]
