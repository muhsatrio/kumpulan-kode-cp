#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adjacencyMatrix(n+1);
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    
    for (int i = 1; i <= n; i++) {
        vector<int> row(n+1, -1);
        adjacencyMatrix[i] = row;
    }
    
    for (int i = 0; i < edges.size(); i++) {
        adjacencyMatrix[edges[i][0]][edges[i][1]] = 1;
        adjacencyMatrix[edges[i][1]][edges[i][0]] = 1;
    }
    
    dist[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    int layer = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        layer = dist[u];
        
        for (int v = 1; v <= n; v++) {
            if (adjacencyMatrix[u][v] == 1) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }
    
    vector<int> result;
    
    for (int v = 1; v <= n; v++) {
        if (dist[v] != 0) {
            if (dist[v] == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(dist[v] * 6);
            }
        }
    }
    
    return result;
}

int main() {

}