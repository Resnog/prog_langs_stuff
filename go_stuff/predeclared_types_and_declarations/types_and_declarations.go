// This is how you can declare a variable in Go

package main

import "fmt"

func try_complex_numbers() {
	var aComplexNumber = 1 + 2i
	var anotherComplexNumber = complex(20.1, 0.3)
	fmt.Println(aComplexNumber, " ", anotherComplexNumber)
}

const (
	tacos            = "Yummy"
	gin              = "Tonic"
	pi_approximation = 3.14159
	pi_complex       = 3.14159 + 0i
	complex_tacos    = real(pi_complex) + imag(pi_complex)
	value            = 20
)

func main() {
	var aVariable = "Greetings and \n\"Salutations\""
	fmt.Println(aVariable)

	var anotherVariable int8 = value
	var yetAnotherVariable int16 = int16(anotherVariable) + 1
	var aFloatVariable float32 = 213.123

	fmt.Println("Another variable is", anotherVariable, "and yet another variable is", yetAnotherVariable)

	var yourBoolean = true
	fmt.Println("Your boolean is", yourBoolean)

	try_complex_numbers()

	anotherVariable = 42
	aFloatVariable = float32(anotherVariable) + 0.1
	fmt.Println("Another variable now is", anotherVariable)
	fmt.Println("A float variable is", aFloatVariable)

	var b byte = 255
	var smallI int32 = 2147483647
	var bigI uint64 = 18446744073709551615
	fmt.Println("Byte is", b, "int32 is", smallI, "uint64 is", bigI)
	fmt.Println("Byte is", b+1, "int32 is", smallI+1, "uint64 is", bigI+1)
}
