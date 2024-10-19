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
	@go build -o composite_types

run: build
	@echo "Running..."
	@./composite_types

clean:
	@echo "Cleaning up..."
	@rm -f composite_types
