#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[1001][31];

int price[1001];

int weight[1001];

int countMaxPrice(int i, int currentWeight, int N) {
    if ((i == N) || currentWeight == 0) {
        return 0;
    }

    int &result = memo[i][currentWeight];

    if (result != -1) {
        return result;
    }

    if (weight[i] > currentWeight) {
        return result = countMaxPrice(i+1, currentWeight, N);
    }

    return result = max(countMaxPrice(i+1, currentWeight, N), price[i] + countMaxPrice(i+1, currentWeight-weight[i], N));
}

int main() {
    int T, P, W, N, G, max_weight, MG;

    cin >> T;

    for (int i = 0; i < T; i++) {
        memset(memo, -1, sizeof memo);

        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> P >> W;
            price[j] = P;
            weight[j] = W;
        }

        cin >> G;

        max_weight = 0;

        for (int j=0; j < G; j++) {
            cin >> MG;
            max_weight+=countMaxPrice(0, MG, N);
        }

        cout << max_weight << endl;
    }
}