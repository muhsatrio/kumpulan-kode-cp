#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(vector<vector<int> > graph, vector<bool>& visited, int start, int& result) {
    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        result++;

        for (auto nextNode : graph[currNode]) {
            if (!visited[nextNode]) {
                q.push(nextNode);
            }
        }
    }
}

int main() {
    int t, n, tempP;

    cin >> t;

    while (t--) {
        cin >> n;

        vector<vector<int> > graph(n+1);
        vector<bool> visited(n+1);

        for (int i=2; i<=n; i++) {
            cin >> tempP;
            graph[tempP].push_back(i);
        }

        int result = 0;

        bfs(graph, visited, 1, result);

        cout << result << endl;
        
    }
}