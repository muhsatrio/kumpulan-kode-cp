// A government wants to build a highway connecting all cities.

// However, due to the high cost, the government wants to ensure travel between all cities at the lowest possible cost.

// There is also an additional constraint: to ensure eco-friendly construction without cutting down hills, some cities cannot be directly connected by roads.

// Given a list of roads that can be connected for eco-friendly construction, help the government find the minimum cost to build a highway connecting all cities.


// [Input]

// The first line contains the number of test cases, T. (1 ≤ T ≤ 8).

// The first line of each test case contains the number of cities, N. (2 ≤ N ≤ 50,000).

// The second line of each test case contains the number of road candidates, M. (1 ≤ M ≤ 200,000)

// . Starting from the third line of each test case, the M lines contain information about each road candidate, s, e, and c.

// s and e are the numbers of each city that the road candidate connects, and c is the cost of building the road. (1 ≤ c ≤ 10,000)

// Only inputs that can build a highway connecting all cities are given.

// [Output]

// For each test case, print the number of test cases “#(TC) “ on a single line, and print the minimum cost of building a highway connecting all cities.
 

// input
// 1
// 5
// 8
// 1 2 4
// 1 3 9
// 1 4 21
// 2 3 8 2 4
// 17 3 4
// 16 5
// 2 20
// 5 4 30	

// output
// #1 48

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