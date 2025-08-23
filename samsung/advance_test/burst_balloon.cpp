/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/

#include <vector>

using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> a;
    a.push_back(1);
    int i = 0;
    while (i < n) {
        a.push_back(nums[i]);
        i++;
    }
    a.push_back(1);
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for (int i=1; i<=n; i++) {
        dp[i][i] = a[i-1] * a[i] * a[i+1];
    }

    // showDp(dp, n);

    for (int len=2; len <= n; len++) {
        for (int i=1; i<=n-len+1; i++) {
            int j = i + len - 1;

            for (int k=i; k<=j; k++) {
                int t = a[i-1] * a[k] * a[j+1];

                if (i <= k-1) {
                    t+=dp[i][k-1];
                }

                if (j>=k+1) {
                    t+=dp[k+1][j];
                }

                dp[i][j] = max(dp[i][j], t);

                // showDp(dp, n);
            }
        }
    }

    return dp[1][n];
}

int main() {
    return 0;
}