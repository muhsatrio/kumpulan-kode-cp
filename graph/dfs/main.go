package main

import "fmt"

var adjacencyMatrix [2000][2000]int
var dfsVisited [2000]int

var VISITED int = -2
var UNVISITED int = -1

func dfs(u int, V int) {
	fmt.Printf("%d ", u)
	dfsVisited[u] = VISITED
	for i := 1; i <= V; i++ {
		if adjacencyMatrix[u][i] == 1 && dfsVisited[i] == UNVISITED {
			dfs(i, V)
		}
	}
}

func main() {
	var V, E, x, y int
	fmt.Scanf("%d", &V)
	for i := 1; i <= V; i++ {
		dfsVisited[i] = UNVISITED
	}
	fmt.Scanf("%d", &E)
	for i := 0; i < E; i++ {
		fmt.Scanf("%d %d", &x, &y)
		adjacencyMatrix[x][y] = 1
		adjacencyMatrix[y][x] = 1
	}

	totalWays := 0

	for i := 1; i <= V; i++ {
		if dfsVisited[i] == UNVISITED {
			totalWays++
			dfs(i, V)
			fmt.Println()
		}
	}

	fmt.Println("total Ways: ", totalWays)
}
