#include <iostream>
#include <map>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int officeX, officeY, homeX, homeY;
        cin >> officeX >> officeY >> homeX >> homeY;

        vector<pair<int,int> > points;
        points.push_back(make_pair(officeX, officeY)); // 0 = office

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x, y)); // 1..n = customers
        }

        points.push_back(make_pair(homeX, homeY)); // n+1 = home

        int totalNodes = n + 2;
        int homeIndex = n + 1;

        // Precompute distances
        vector<vector<int> > dist(totalNodes, vector<int>(totalNodes));
        for (int i = 0; i < totalNodes; i++) {
            for (int j = 0; j < totalNodes; j++) {
                dist[i][j] = abs(points[i].first - points[j].first) +
                             abs(points[i].second - points[j].second);
            }
        }

        // DP table
        int FULL = 1 << (n + 1); // we exclude home from visited mask
        const int INF = 1e9;
        vector<vector<int> > dp(FULL, vector<int>(n+1, INF));

        dp[1][0] = 0; // start at office, mask = only office visited

        // Iterate over all masks
        for (int mask = 1; mask < FULL; mask++) {
            for (int u = 0; u <= n; u++) { // last visited node (0..n, exclude home)
                if (!(mask & (1 << u))) continue; // u not in mask
                if (dp[mask][u] == INF) continue;

                for (int v = 1; v <= n; v++) { // try going to another customer
                    if (mask & (1 << v)) continue; // already visited
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] = min(dp[nextMask][v],
                                          dp[mask][u] + dist[u][v]);
                }
            }
        }

        // Final: all customers visited, go to home
        int result = INF;
        int allVisited = (1 << (n+1)) - 1; // office + all customers
        for (int u = 0; u <= n; u++) {
            if (dp[allVisited][u] < INF) {
                result = min(result, dp[allVisited][u] + dist[u][homeIndex]);
            }
        }

        cout << result << "\n";
    }

    return 0;
}
