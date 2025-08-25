/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/

#include <iostream>
#include <vector>

using namespace std;

int countDp(vector<int>& ballons, vector<vector<int> >& dp, int left, int right) {
  if (right - left == 0) return 0;
  
  if (dp[left][right] != -1) return dp[left][right];
  
  int ans = 0;
  
  for (int i=left+1; i<right; i++) {
    int coins = ballons[left] * ballons[i] * ballons[right] + countDp(ballons, dp, left, i) + countDp(ballons, dp, i, right);
    ans = max(ans, coins);
  }
  
  dp[left][right] = ans;
  
  return ans;
}

int main() 
{
  int t, n, temp;
  cin >> t;
  
  while (t--) {
    cin >> n;
    vector<int> ballons;
    for (int i=0; i<n; i++) {
      cin >> temp;
      ballons.push_back(temp);
    }
    
    ballons.insert(ballons.begin(), 1);
    
    ballons.push_back(1);
    
    vector<vector<int> > dp(n+2, vector<int>(n+2, -1));
    
    cout << countDp(ballons, dp, 0, n+1) << endl;
    
  }
  return 0;
}