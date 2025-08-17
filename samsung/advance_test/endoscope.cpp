// 2 
// 5 6 2 1 3 
// 0 0 5 3 6 0 
// 0 0 2 0 2 0 
// 3 3 1 3 7 0 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 5 6 2 2 6 
// 3 0 0 0 0 3 
// 2 0 0 0 0 6 
// 1 3 1 1 3 1 
// 2 0 2 0 0 2 
// 0 0 4 3 1 1

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void assignDirection(unordered_map<int, vector<pair<int, int> > >& directions) {
    vector<pair<int, int> > directionOne;
    directionOne.push_back(make_pair(0, 1));
    directionOne.push_back(make_pair(0, -1));
    directionOne.push_back(make_pair(1, 0));
    directionOne.push_back(make_pair(-1, 0));
    directions[1] = directionOne;

    vector<pair<int, int> > directionTwo;
    directionTwo.push_back(make_pair(1, 0));
    directionTwo.push_back(make_pair(-1, 0));
    directions[2] = directionTwo;

    vector<pair<int, int> > directionThree;
    directionThree.push_back(make_pair(0, 1));
    directionThree.push_back(make_pair(0, -1));
    directions[3] = directionThree;

    vector<pair<int, int> > directionFour;
    directionFour.push_back(make_pair(0, 1));
    directionFour.push_back(make_pair(-1, 0));
    directions[4] = directionFour;

    vector<pair<int, int> > directionFive;
    directionFive.push_back(make_pair(0, 1));
    directionFive.push_back(make_pair(1, 0));
    directions[5] = directionFive;

    vector<pair<int, int> > directionSix;
    directionSix.push_back(make_pair(0, -1));
    directionSix.push_back(make_pair(1, 0));
    directions[6] = directionSix;

    vector<pair<int, int> > directionSeven;
    directionSeven.push_back(make_pair(0, -1));
    directionSeven.push_back(make_pair(-1, 0));
    directions[7] = directionSeven;
}

bool isConnected(pair<int, int> currDir, int nextSubDir, unordered_map<int, vector<pair<int, int> > > directions) {
    pair<int, int> opposite = make_pair(-currDir.first, -currDir.second);

    for (pair<int, int> d : directions[nextSubDir]) {
        if (d == opposite) return true;
    }

    return false;
}

void bfs(vector<vector<int> > grids, vector<vector<bool> >& visited, unordered_map<int, vector<pair<int, int> > > directions, int n, int m, pair<int, int> start, int l, int& result) {
    queue<pair<int, int> > q;
    int y, x;
    
    q.push(start);

    result = 1;
    int time = 1;

    visited[start.first][start.second] = true;

    while (!q.empty() && time < l) {
        int sz = q.size();
        while (sz--) {
            auto [y, x] = q.front();
            
            q.pop();

            for (pair<int, int> eachCurrDirection : directions[grids[y][x]]) {
                int ny = y + eachCurrDirection.first;
                int nx = x + eachCurrDirection.second;
    
                if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                    if (!visited[ny][nx] && grids[ny][nx] != 0) {
                        if (isConnected(eachCurrDirection, grids[ny][nx], directions)) {
                            visited[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                            result++;
                        }
                    }
                }
            }
        }
        time++;
    }
}

int main() {
    int t, n, m, r, c, l;

    unordered_map<int, vector<pair<int, int> > > directions;

    assignDirection(directions);

    cin >> t;

    while (t--) {
        cin >> n >> m >> r >> c >> l;
        vector<vector<int> > grids(n, vector<int>(m));
        vector<vector<bool> > visited(n, vector<bool>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> grids[i][j];
            }
        }

        int result = 0;
        pair<int, int> start = make_pair(r, c);

        bfs(grids, visited, directions, n, m, start, l, result);

        cout << result << endl;
    }
}