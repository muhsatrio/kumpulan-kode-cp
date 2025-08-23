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
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct state {
    int x;
    int y;
    int difficulty;
};


int main() {
    int t, n, m;

    cin >> t;

    while (t--) {
        cin >> n >> m;

        vector<vector<int> > grids(n, vector<int>(m));

        vector<vector<bool> > visited(n, vector<bool>(m));

        vector<pair<int, int> > directions;

        directions.push_back(make_pair(0, 1));
        directions.push_back(make_pair(0, -1));
        directions.push_back(make_pair(1, 0));
        directions.push_back(make_pair(-1, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> grids[i][j];
            }
        }

        queue<state> q;

        state startState = {n-1, 0, 0};

        int result = INT_MAX;

        q.push(startState);

        while (!q.empty()) {
            state currState = q.front();
            q.pop();
            auto [currY, currX, currDifficulty] = currState;

            visited[currY][currX] = true;

            if (grids[currY][currX] == 3) {
                result = min(result, currDifficulty);
            }

            for (auto [dirrY, dirrX] : directions) {
                if (dirrY != 0) {
                    int nextY = currY + dirrY;
                    int nextDifficulty = 0;
                    while (nextY < n && nextY >= 0) {
                        if ((grids[nextY][currX] == 1 || grids[nextY][currX] == 3) && !visited[nextY][currX]) {
                            state nextState = {nextY, currX, currDifficulty + nextDifficulty};
                            q.push(nextState);
                        }
                        nextDifficulty++;
                        nextY+=dirrY;
                    }
                } else {
                    if (currX + dirrX >= 0 && currX + dirrX < m) {
                        if (grids[currY][currX + dirrX] == 1 && !visited[currY][currX + dirrX]) {
                            state nextState = {currY, currX + dirrX, currDifficulty};
                            q.push(nextState);
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}