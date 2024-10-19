.DEFAULT_GOAL := build

.PHONY: fmt vet build

fmt:
	@echo "Formatting..."
	@go fmt ./...

vet:
	@echo "Vetting..."
	@go vet ./...

build: vet
	@echo "Building..."
	@go build -o hello_world

clean:
	@echo "Cleaning up..."
	@rm -f hello_world
