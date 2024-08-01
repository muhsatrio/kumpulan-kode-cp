package main

import "fmt"

var coinValue = [5]int{50, 25, 10, 5, 1}

var memo [5][7490]int

func countWays(n int, value int) int {
	if value == 0 {
		return 1
	}

	if value < 0 || n == 5 {
		return 0
	}

	if memo[n][value] != 0 {
		return memo[n][value]
	}

	return countWays(n+1, value) + countWays(n, value-coinValue[n])
}

func main() {
	var n int

	fmt.Scanf("%d", &n)

	fmt.Println(countWays(0, n))
}
