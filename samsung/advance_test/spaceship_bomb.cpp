#include <iostream>
#include <queue>

using namespace std;

struct State {
  int y;
  int x;
  int numCoins;
  bool usedBomb;
  vector<vector<int> > grids;
};

void useBomb(vector<vector<int> >& grids, int y) {
  for (int i=max(0, y-4); i<=y; i++) {
    for (int j=0; j<5; j++) {
      if (grids[i][j] == 2) {
        grids[i][j] = 0;
      }
    }
  }
}

int main() 
{
  int t, n;
  
  cin >> t;
  
  while (t--) {
    cin >> n;
    
    vector<vector<int> > grids(n+1, vector<int>(5));
    
    vector<pair<int, int> > directions;
    
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(-1, 1));
    directions.push_back(make_pair(-1, -1));
    
    for (int i=0; i<n; i++) {
      for (int j=0; j<5; j++) {
        cin >> grids[i][j];
      }
    }
    
    int result = 0;
    
    queue<State> q;
    
    State startState = {n, 2, 0, false, grids};
    
    q.push(startState);
    
    while (!q.empty()) {
      auto [currY, currX, currNumCoins, usedBomb, currGrids] = q.front();
      q.pop();
      
      result = max(result, currNumCoins);
      
      for (auto [dirrY, dirrX] : directions) {
        int nextY = currY + dirrY;
        int nextX = currX + dirrX;
        
        if (nextY >= 0 && nextX >= 0 && nextX < 5) {
          if (currGrids[nextY][nextX] == 1) {
            State nextState = {nextY, nextX, currNumCoins+1, usedBomb, currGrids};
            q.push(nextState);
          } else if (currGrids[nextY][nextX] == 2) {
            if (!usedBomb) {
              auto nextGrids = currGrids;
              usedBomb = true;
              useBomb(nextGrids, nextY);
              State nextState = {nextY, nextX, currNumCoins, usedBomb, nextGrids};
              q.push(nextState);
            }
          } else {
            State nextState = {nextY, nextX, currNumCoins, usedBomb, currGrids};
            q.push(nextState);
          }
        }
      }
    }
    
    cout << result << endl;
  }
  return 0;
}