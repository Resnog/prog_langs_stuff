package main

import (
	"fmt"
	"os"
)

var go_makefile = `DEFAULT_GOAL := run\n
\n
.PHONY: fmt vet build run clean\n
\n
fmt:\n
	@echo "Formatting..."\n
	@go fmt ./...\n
\n
vet: fmt\n
	@echo "Vetting..."\n
	@go vet ./...\n
\n
build: vet\n
	@echo "Building..."\n
	go build -o bob\n
\n
run: build\n
	@echo "Running..."\n
	@./bob\n
\n
clean:\n
	@echo "Cleaning up..."\n
	@rm -f ./bob\n
`

// Create and write to a file name CMakeLists.txt
func create_cmake_cmakelist_txt() {
	file, err := os.Create("CMakeLists.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
}

func main() {

	var user_input string

	fmt.Println("Hello, I'm Bob!\nI write some templates for the following topics:")
	fmt.Println("1. Makefile for a Go project that should look like this:")
	//fmt.Println(go_makefile)
	//fmt.Println("2. A new C project you're working on, with CMake and src and inc directories")
	//fmt.Println("3. A new C++ project you're working on, with CMake and src and inc directories")

	user_input, _ = fmt.Sscan(user_input)

}
