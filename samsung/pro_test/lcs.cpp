#include <iostream>
#include <vector>

using namespace std;

int countDP(int i, int j, vector<vector<int>>& memo, string& a, string &b) {
  if (i >= a.length() || j >= b.length()) return 0;
  
  if (memo[i][j] != -1) return memo[i][j];
  
  if (a[i] == b[j]) {
    return memo[i][j] = 1 + countDP(i+1, j+1, memo, a, b);
  } else {
    return memo[i][j] = max(countDP(i+1, j, memo, a, b), countDP(i, j+1, memo, a, b)); 
  }
}

int main() 
{
  int t;
  
  cin >> t;
  
  while (t--) {
    string a;
    string b;
    cin >> a;
    cin >> b;
    
    vector<vector<int>> memo(a.length(), vector<int>(b.length(), -1));
    
    cout << countDP(0, 0, memo, a, b) << endl;
  }
  return 0;
}
