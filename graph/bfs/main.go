package main

import "fmt"

var adjacencyMatrix [2000][2000]int
var dist [2000]int

var INF = 999999

var parent [2000]int

type queue struct {
	datas []int
}

func (q *queue) push(value int) []int {
	q.datas = append(q.datas, value)
	return q.datas
}

func (q *queue) pop() []int {
	q.datas = q.datas[1:]
	return q.datas
}

func (q queue) empty() bool {
	return len(q.datas) <= 0
}

func (q queue) front() int {
	return q.datas[0]
}

func main() {
	var V, E, x, y, startPoint int

	fmt.Scanf("%d %d", &V, &E)

	for i := 1; i <= V; i++ {
		dist[i] = INF
		parent[i] = -1
	}

	for i := 0; i < E; i++ {
		fmt.Scanf("%d %d", &x, &y)
		adjacencyMatrix[x][y] = 1
		adjacencyMatrix[y][x] = 1
	}

	fmt.Scanf("%d", &startPoint)

	dist[startPoint] = 0

	var q queue

	q.push(startPoint)

	layer := -1
	isBipartite := true

	for !q.empty() {
		u := q.front()
		fmt.Println(q.front())
		q.pop()
		if dist[u] != layer {
			fmt.Printf("\nLayer %d\n", dist[u])
		}
		layer = dist[u]
		fmt.Printf("visit %d\n", u)
		for v := 1; v <= V; v++ {
			if adjacencyMatrix[u][v] == 1 {
				if dist[v] == INF {
					dist[v] = dist[u] + 1
					parent[v] = u
					q.push(v)
				} else if dist[v]%2 == dist[u]%2 {
					isBipartite = true
				}
			}
		}
	}

	fmt.Println("Dist: ")

	for i := 1; i < V; i++ {
		fmt.Printf("Edge %d: %d\n", i, dist[i])
	}

	fmt.Println(isBipartite)
}
