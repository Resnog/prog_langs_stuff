.DEFAULT_GOAL := run

.PHONY: fmt vet build run clean

fmt:
	@echo "Formatting..."
	@go fmt ./...

vet: fmt
	@echo "Vetting..."
	@go vet ./...

build: vet
	@echo "Building..."
	go build -o bob

run: build
	@echo "Running..."
	@./bob

clean:
	@echo "Cleaning up..."
	@rm -f ./bob
