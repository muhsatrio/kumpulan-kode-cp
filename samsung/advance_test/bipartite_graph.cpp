#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& graph, vector<int>& visited, int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        for (int nextNode : graph[currNode]) {
            if (visited[nextNode] == -1) {
                if (visited[currNode] == 0) {
                    visited[nextNode] = 1;
                } else {
                    visited[nextNode] = 0;
                }
                q.push(nextNode);
            } else if (visited[currNode] == visited[nextNode]) {
                return false;
            }
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, -1);

    for (int i=0; i<n; i++) {
        if (visited[i] == -1) {
            bool ans = bfs(graph, visited, i);

            if (!ans) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    return 0;
}