#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Node {
    int y, x, steps;
};

void bfs(const vector<vector<int> >& grids, const vector<pair<int, int> >& directions, const pair<int, int>& maxLength, vector<vector<bool> >& visited, Node start, int& result) {
    queue<Node> q;

    q.push(start);

    auto [startY, startX, startSteps] = start;

    auto [maxY, maxX] = maxLength;

    while (!q.empty()) {
        auto currPos = q.front();

        q.pop();

        auto [currY, currX, currSteps] = currPos;

        if (currY == 1 || currY == maxY || currX == 1 || currX == maxX) {
            result = min(result, currSteps);
            return;
        }

        visited[currY][currX] = true;
        
        for (auto& [dirrY, dirrX] : directions) {
            int nextY = currY + dirrY;
            int nextX = currX + dirrX;

            if (nextX >= 1 && nextX <= maxX && nextY >= 1 && nextY <= maxY) {
                if (!visited[nextY][nextX] && grids[nextY][nextX] == 0) {
                    q.push({ nextY, nextX, currSteps+1});
                }
            }
        }
    }
}

// void dfs(const vector<vector<int> >& grids, const vector<pair<int, int> >& directions, const pair<int, int>& maxLength, vector<vector<bool> >& visited, pair<int, int> currPos, int totalSteps, int& result) {
//     auto [y, x] = currPos;

//     auto [maxY, maxX] = maxLength;

//     visited[y][x] = true;

//     totalSteps++;

//     if (y == 1 || y == maxY || x == maxX || x == 1) {
//         result = min(result, totalSteps);
//         visited[y][x] = false;
//         return;
//     }

//     for (auto& [dirY, dirX] : directions) {
//         int nextX = x + dirX;
//         int nextY = y + dirY;

//         if (nextX >= 1 && nextX <= maxX && nextY >= 1 && nextY <= maxY) {
//             if (!visited[nextY][nextX] && grids[nextY][nextX] == 0) {
//                 dfs(grids, directions, maxLength, visited, make_pair(nextY, nextX), totalSteps, result);
//             }
//         }
//     }

//     visited[y][x] = false;
// }

int main() {
    int n, m, startY, startX;

    cin >> n >> m;

    vector<vector<int> > grids(n+1, vector<int>(m+1));
    vector<vector<bool> > visited(n+1, vector<bool>(m+1));

    vector<pair<int, int> > directions;

    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(0, -1));
    

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> grids[i][j];
        }
    }

    cin >> startY >> startX;

    int result = INT_MAX;

    Node start;

    start.y = startY;
    start.x = startX;
    start.steps = 0;

    bfs(grids, directions, make_pair(n, m), visited, start, result);

    cout << result << endl;

    return 0;
}