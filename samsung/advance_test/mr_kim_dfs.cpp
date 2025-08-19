#include <iostream>
#include <map>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

string joinIntAndConvertToString(int a, int b) {
  return to_string(a) + "," + to_string(b);
}

int countDistance(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

bool allVisited(const unordered_map<string, bool>& visited) {
    for (auto [key, value] : visited) {
        if (!value) return false;
    }
    return true;
}

void dfs(unordered_map<string, vector<pair<string, pair<int, int> > > > graph, unordered_map<string, bool>& visited, pair<int, int> endPoint, pair<string, pair<int, int> > currState, int totalDistance, int& result) {
    auto [currNode, currPoint] = currState;
    auto [x1, y1] = currPoint;

    visited[currNode] = true;

    if (allVisited(visited)) {
        auto [x2, y2] = endPoint;
        result = min(result, totalDistance + countDistance(x1, y1, x2, y2));
        visited[currNode] = false;
    }
    
    for (auto nextState : graph[currNode]) {
        if (!visited[nextState.first]) {
            auto [x2, y2] = nextState.second;
            dfs(graph, visited, endPoint, nextState, totalDistance + countDistance(x1, y1, x2, y2), result);
        }
    }

    visited[currNode] = false;
}

int main() {
    
  int t, n, homeX, homeY, officeX, officeY, tempX, tempY;
  
  cin >> t;
  
  while (t--) {
    unordered_map<string, vector<pair<string, pair<int, int> > > > graph;
  
    unordered_map<string, bool> visited;
    cin >> n;
  
    cin >> officeX >> officeY >> homeX >> homeY;

    vector<pair<string, pair<int, int> > > initList;
    
    graph[joinIntAndConvertToString(officeX, officeY)] = initList;
    visited[joinIntAndConvertToString(officeX, officeY)] = false;
    
    
    for (int i=0; i<n; i++) {
      cin >> tempX >> tempY;
      visited[joinIntAndConvertToString(tempX, tempY)] = false;

      initList.push_back(make_pair(joinIntAndConvertToString(tempX, tempY), make_pair(tempX, tempY)));
    }

    for (int i=0; i<initList.size(); i++) {
        auto tempState = initList;
        tempState.erase(tempState.begin() + i);
        graph[initList[i].first] = tempState;
        graph[joinIntAndConvertToString(officeX, officeY)].push_back(initList[i]);
    }

    int result = INT_MAX;

    dfs(graph, visited, make_pair(homeX, homeY), make_pair(joinIntAndConvertToString(officeX, officeY), make_pair(officeX, officeY)), 0, result);

    cout << result << endl;
  }
    
  return 0;
}