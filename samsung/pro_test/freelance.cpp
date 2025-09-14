// Imagine a freelance interior designer.

// Because he's a renowned interior designer, he receives numerous requests.

// However, if two requests overlap, he can't fulfill both schedules.

// Therefore, he must organize his schedules with non-overlapping requests. Furthermore, he receives payment for each request completed. 

// Our goal is to select the schedule that yields the highest amount of payment among the available schedules.



// Let's say there are seven schedules, as shown above.

// An overlapping schedule means that if T3 is selected, T2, T6, T8, etc. cannot be selected.

// A feasible schedule is one that doesn't overlap, such as {T1, T4}, {T8, T2, T4}.

// Write a program that calculates the maximum amount of payment for each of these possible schedules.


// [Input]

// The first line contains the number of test cases, T. (1 ≤ T ≤ 10)

// The first line of each test case contains the number of requested days N and the total number of days M. (1 ≤ N ≤ 500, 1 ≤ M ≤ 10000)

// Then, three integers si, ei, and ci are given over N lines separated by spaces.

// si and ei represent the start date and the end date of request i, respectively, and ci represents the price of the request. (0 ≤ si ≤ ei ≤ 10,000, 0 ≤ ci ≤ 10,000)

// [Output]

// For each test case, print the number of test cases “#(TC) “ on one line, and print the maximum possible amount.

// input
// 1
// 9 10
// 1 5 30
// 4 7 25
// 2 9 42
// 8 10 9
// 1 4 20 5
// 9 27 7
// 10 16
// 1 3 15
// 5 7 7	

// output
// #1 49

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Request {
    int s;
    int e;
    int c;
};

bool compareRequestEndTime(const Request a, const Request b) {
    return a.e < b.e;
}

int findPrevious(int i, vector<int>& ends, vector<Request>& reqs) {
    int s = reqs[i].s;

    int idx = upper_bound(ends.begin(), ends.end(), s-1) - ends.begin();

    return idx-1;
}

int solveDP(int i, vector<int>& dp,  vector<int>& ends, vector<Request>& reqs) {
    if (i < 0) return 0;

    if (dp[i] != -1) return dp[i];

    int result = solveDP(i-1, dp, ends, reqs);

    int prevIdx = findPrevious(i, ends, reqs); 

    result = max(result, reqs[i].c + solveDP(prevIdx, dp, ends, reqs));

    return dp[i] = result;
}

int main() {
    int t;

    cin >> t;

    for (int tc=1; tc<=t; tc++) {
        int n, m;

        cin >> n >> m;

        vector<Request> reqs(n+1);

        for (int i=0; i<n; i++) {
            cin >> reqs[i].s >> reqs[i].e >> reqs[i].c; 
        }

        sort(reqs.begin(), reqs.end(), compareRequestEndTime);

        vector<int> ends(n+1);

        for (int i=0; i<n; i++) {
            ends[i] = reqs[i].e;
        }

        vector<int> dp(n+1, -1);

        int result = solveDP(n-1, dp, ends, reqs);

        cout << "#" << tc << " " << result << endl;
    }
}