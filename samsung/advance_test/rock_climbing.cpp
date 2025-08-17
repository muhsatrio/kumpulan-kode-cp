/*
Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important.
There is more than one path from the starting point to the destination point. 
Output: The minimum level of difficulty of all rock climbing paths level.
Constraints

1 <= N,M <= 10

Output Format

Single interger "level"

Sample Input 0
1
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Sample Output 0

2

*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

void dfs(vector<vector<int> > grids, int n, int m, pair<int, int> node, vector<vector<int> >& visited, vector<pair<int, int> >& directions, int totalDifficulty, int& result) {
    int y = node.first; int x = node.second;

    if (y < 0 || y >= n || x < 0 || x >= m) return;

    if (visited[y][x]) return;

    if (grids[y][x] == 3) {
        result = min(result, totalDifficulty);
        return;
    }

    visited[y][x] = 1;

    for (auto direction : directions) {
        int nextY = y + direction.first;
        int nextX = x + direction.second;

        if (direction.first != 0) {
            int tempY = nextY, tempX = nextX;
            int tempDifficulty = 0;
            while (tempY < n && tempY >= 0) {
                tempDifficulty++;
                if (nextY < n && nextY >= 0) {
                    if ((grids[tempY][tempX] == 1 || grids[nextY][nextX] == 3)) {
                        dfs(grids, n, m, make_pair(nextY, nextX), visited, directions, totalDifficulty + (tempDifficulty > 1 ? tempDifficulty - 1 : 0), result);
                    }
                }
                tempY +=  direction.first;
            }
        } else {
            if (nextY >= 0 && nextY < n && nextX >=0 && nextX < m) {
                if ((grids[nextY][nextX] == 1 || grids[nextY][nextX] == 3)) {
                    dfs(grids, n, m, make_pair(nextY, nextX), visited, directions, totalDifficulty, result);
                }
            }
        }
    }

    visited[y][x] = 0;
}

int main() {
    int t, n, m;

    vector<pair<int, int> > directions;
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, -1));
    directions.push_back(make_pair(0, 1));

    cin >> t;

    while (t--) {
        string temp;
        cin >> n >> m;
        vector<vector<int> > grids(n, vector<int>(m));
        vector<vector<int> > visited(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> grids[i][j];
            }
        }

        pair<int, int> start = make_pair(n-1, 0);

        int result = INT_MAX;

        int totalDifficulty = 0;

        dfs(grids, n, m, start, visited, directions, totalDifficulty, result);

        cout << result << endl;
    }

    return 0;
}