package main

import "fmt"

var dr []int = []int{1, 1, 0, -1, -1, -1, 0, 1}
var dc []int = []int{0, 1, 1, 1, 0, -1, -1, -1}

var grid []string
var backupGrid []string

func replaceAt(S string, i int, c string) string {
	return S[:i] + c + S[i+1:]
}

func floodFill(r int, c int, c1 string, c2 string, maxR int, maxC int) int {
	if r < 0 || r >= maxR || c < 0 || c >= maxC {
		return 0
	}

	splittedRow := []rune(grid[r])

	if string(splittedRow[c]) != c1 {
		return 0
	}

	var ans = 1

	grid[r] = replaceAt(grid[r], c, c2)

	for i := 0; i < 8; i++ {
		ans += floodFill(r+dr[i], c+dc[i], c1, c2, maxR, maxC)
	}

	return ans
}

func main() {
	var R, C, N, r, c int
	var S string

	fmt.Scanf("%d %d", &R, &C)

	for i := 0; i < R; i++ {
		fmt.Scanf("%s", &S)
		grid = append(grid, S)
	}

	backupGrid = grid

	fmt.Scanf("%d", &N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d %d", &r, &c)
		fmt.Println(floodFill(r, c, "W", ".", R, C))
		grid = backupGrid
	}
}
