#include <vector>

using namespace std;

// void showDp(vector<vector<int>> dp, int n) {
    //     for (int i=0; i<=n; i++) {
    //         for (int j=0; j<=n; j++) {
    //             cout << dp[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
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