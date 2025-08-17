package main

import (
	"fmt"
	"strconv"
)

func LargestPair(num int) int {
	convertedInt := strconv.Itoa(num)
	result := 0
	lenNum := len(convertedInt)
	for i := 0; i < lenNum-1; i++ {
		firstDigit, _ := strconv.Atoi(string(convertedInt[i]))
		secondDigit, _ := strconv.Atoi(string(convertedInt[i+1]))
		temp := (firstDigit * 10) + secondDigit
		if temp > result {
			result = temp
		}
	}
	// code goes here
	return result

}

func main() {

	// do not modify below here, readline is our function
	// that properly reads in the input for you
	fmt.Println(LargestPair(4759472))

}
