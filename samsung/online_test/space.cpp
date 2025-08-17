#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

void solve(const int n, const int p1, const int p2) {
    set<int> seen;
    vector<int> queries(n);
    for (int& query: queries) {
        cin >> query;
        seen.insert(query);
    }
    
    vector<int> sorted;
    unordered_map<int,int> cost;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (const int& num: seen) {
        const int min_cost = min(abs(num - p1), abs(num - p2));
        cost[num] = min_cost;
        pq.push({min_cost, sorted.size()});
        sorted.push_back(num);
    }
    
    while (!pq.empty()) {
        const auto [curr_cost, start_index] = pq.top();
        pq.pop();
        for (int l = start_index - 1; l >= 0; l--) {
            const int shift_cost = max(sorted[l+1] - sorted[l], cost[sorted[l+1]]);
            if (cost[sorted[l]] <= shift_cost) {
                break;
            }
            cost[sorted[l]] = shift_cost;
        }
        for (int r = start_index + 1; r < sorted.size(); r++) {
            const int shift_cost = max(sorted[r] - sorted[r-1], cost[sorted[r-1]]);
            if (cost[sorted[r]] <= shift_cost) {
                break;
            }
            cost[sorted[r]] = shift_cost;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << cost[queries[i]] << (i == n - 1 ? "\n" : " ");
    }
}


int main() {
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n, p1, p2;
        cin >> n >> p1 >> p2;
        solve(n, p1, p2);
    }

    return 0;
}