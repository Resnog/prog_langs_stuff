.DEFAULT_GOAL := build

.PHONY: fmt vet build

fmt:
	@echo "Formatting..."
	@go fmt ./...

vet: fmt
	@echo "Vetting..."
	@go vet ./...

build: vet
	@echo "Building..."
	@go build -o types_and_declarations

clean:
	@echo "Cleaning up..."
	@rm -f types_and_declarations
