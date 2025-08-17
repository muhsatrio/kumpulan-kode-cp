#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int W[2000], H[2000];
int memo[101][2001];

struct maxPriceItems {
    int maxPrice;
    int currentWeight;
    vector<int> items;
};

maxPriceItems countKnapsack(int i, int currentWeight, int N, int currentValue, vector<int> items) {
    if (i >= N || currentWeight <= 0) {
        return {
            currentValue,
            currentWeight,
            items
        };
    }

    if (memo[i][currentWeight] != -1) {
        return {
            memo[i][currentWeight],
            currentWeight,
            items
        };
    }

    if (W[i] > currentWeight) {
        return countKnapsack(i+1, currentWeight, N, currentValue, items);
    }

    maxPriceItems resultA = countKnapsack(i+1, currentWeight, N, currentValue, items);

    items.push_back(i+1);

    maxPriceItems resultB = countKnapsack(i+1, currentWeight-W[i], N, H[i]+currentValue, items);

    memo[i][currentWeight] = max(resultA.maxPrice, resultB.maxPrice);

    if (resultA.maxPrice > resultB.maxPrice) {
        return resultA;
    } else if (resultA.maxPrice == resultB.maxPrice && resultA.currentWeight < resultB.currentWeight) {
        return resultA;
    }

    return resultB;
}

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    memset(memo, -1, sizeof memo);

    for (int i=0; i < K; i++) {
        int w, h;
        scanf("%d %d", &w, &h);
        W[i] = w;
        H[i] = h;
    }

    vector<int> items;

    maxPriceItems result = countKnapsack(0, N, K, 0, items);

    for (int i = 0; i < result.items.size(); i++) {
        printf("%d\n", result.items[i]);
    }
}