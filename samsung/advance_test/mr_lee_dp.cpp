#include <iostream>
#include <vector>

using namespace std;

int tsp(const int INF, int n, int currPos, int mask, vector<vector<int>>& dp, vector<vector<int>> cost) {
  if (mask == (1 << n) - 1) {
    if (cost[currPos][0] == 0) return INF;
    return cost[currPos][0];
  }
  
  int &res = dp[currPos][mask];
  
  if (res != -1) {
    return res;
  }
  
  res = INF;
  
  for (int i=0; i<n; i++) {
    if (!(mask & (1 << i)) && cost[currPos][i] > 0) {
      res = min(res, cost[currPos][i] + tsp(INF, n, i, mask | (1 << i), dp, cost));
    }
  }
  
  return res;
}

int main() 
{
  int t;
  
  const int INF = 1e9;
  
  cin >> t;
  
  while (t--) {
    int n;
    
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(n));
    
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        cin >> cost[i][j];
      }
    }
    
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    
    cout << tsp(INF, n, 0, 1, dp, cost) << endl;
  }
  
  return 0;
}
