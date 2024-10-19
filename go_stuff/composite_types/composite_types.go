package main

import "fmt"

// Slices increase in double in size usually when appending elements
func slice_examples() {
	// Slices
	fmt.Println("Slices")
	var aSlice = []int{1, 2, 3}
	fmt.Println(aSlice, "len:", len(aSlice), "cap:", cap(aSlice))
	aSlice = append(aSlice, 4, 5, 6)
	fmt.Println(aSlice, "len:", len(aSlice), "cap:", cap(aSlice))
	aSlice = append(aSlice, []int{7, 8, 9}...)
	fmt.Println(aSlice, "len:", len(aSlice), "cap:", cap(aSlice))
	aSlice = append(aSlice, []int{7, 8, 9, 10, 11, 12, 13, 14}...)
	fmt.Println(aSlice, "len:", len(aSlice), "cap:", cap(aSlice))
	fmt.Println("")
}

func slicing_slices() {
	// Slicing slices
	fmt.Println("Slicing slices")
	var aSlice = []int{1, 2, 3, 4, 5}
	fmt.Println(aSlice[1:3])
	fmt.Println(aSlice[1:])
	fmt.Println(aSlice[:3])
	fmt.Println("")
}

func slices_of_slices() {
	fmt.Println("Slices of slices share memory and therefore changes in one slice will reflect in the other")
	var aSlice = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	var bSlice = aSlice[2:5]
	bSlice[0], bSlice[1], bSlice[2] = 30, 40, 50
	fmt.Println("After modifying slices of slices the original one is modified", aSlice, "len:", len(aSlice))
	bSlice = append(bSlice, 60, 70, 80)
	fmt.Println("After appending to slices of slices the original one is modified by having the following values overwritten", aSlice, "len:", len(aSlice))
	fmt.Println("")
}

func copies_of_slices() {
	fmt.Println("Copies of slices do not share memory, and the result of the copy function is the number of elements copied")
	var aSlice = []int{1, 2, 3, 4, 5, 6, 7, 8, 10}
	var bSlice = make([]int, len(aSlice))
	num := copy(bSlice, aSlice)
	fmt.Println(aSlice, bSlice, num)
	fmt.Println("")
}

func arrays_to_slices() {
	// Arrays to slices
	fmt.Println("Arrays to slices")
	var x = [3]int{1, 2, 3}
	var y = x[:]
	fmt.Println(x, y)
	fmt.Println("")
}

func arrays() {
	// Arrays
	fmt.Println("Arrays")
	var x [3]int
	x[0], x[1], x[2] = 1, 2, 3
	var y = [3]int{4, 5, 6}
	var sparseArray = [10]int{0, 4: 4, 5, 8: 8}
	fmt.Println(x)
	fmt.Println(y)
	fmt.Println(sparseArray)
	fmt.Println(x == y)
	fmt.Println("")
}

func strings_and_runes_and_bytes() {
	// Strings, runes and bytes
	fmt.Println("Strings, runes and bytes")
	var s1 = "\"Hello my name is Bob!\""
	var s2 = s1[1:6]
	var someByte = s2[2]
	var msg = "This is a string:"

	fmt.Println(msg + " " + s1)
	fmt.Println(s2)
	fmt.Println(someByte)
}

func main() {
	arrays()
	slice_examples()
	slicing_slices()
	slices_of_slices()
	copies_of_slices()
	arrays_to_slices()
	strings_and_runes_and_bytes()
}
