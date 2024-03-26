package main

import "fmt"

func main() {
	slice := createIntSlice(10)
	for _, num := range slice {
		if num%2 == 0 {
			fmt.Println(num, "even")
		} else {
			fmt.Println(num, "odd")
		}
	}
}

func createIntSlice(upTo int) []int {
	var slice []int
	for i := 1; i <= upTo; i++ {
		slice = append(slice, i)
	}
	return slice
}
