#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int node;
    int cost;
};

bool allVisited(vector<bool>& visited, int n) {
    for (int i=1; i<=n; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int tc=1; tc<=t; tc++) {
        int n, m, s, e, c;

        cin >> n >> m;

        vector<vector<State> > graph(n+1);

        for (int i=0; i<m; i++) {
            cin >> s >> e >> c;
            State tempState;
            tempState.node = e;
            tempState.cost = c;
            graph[s].push_back(tempState);
            tempState.node = s;
            graph[e].push_back(tempState);
        }

        using PII = pair<int, int>;

        priority_queue<PII, vector<PII>, greater<PII> > q;

        q.push(make_pair(0, 1));

        vector<bool> visited(n+1);

        int totalVisited = 0;

        int cost = 0;

        while (!q.empty() && totalVisited < n) {
            auto [currCost, currNode] = q.top();
            q.pop();

            if (visited[currNode]) continue;

            totalVisited++;

            cost+=currCost;
            
            visited[currNode] = true;

            for (auto [nextNode, nextCost] : graph[currNode]) {
                if (!visited[nextNode]) {
                    q.push(make_pair(nextCost, nextNode));
                }
            }
        }

        cout << cost << endl;
    }
    
    return 0;
}