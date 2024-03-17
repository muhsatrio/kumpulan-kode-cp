#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[10000][10000];

int countLCS(string a, string b, int pos_a, int pos_b) {
    if (pos_a == -1 || pos_b == -1) {
        return 0;
    }

    if (memo[pos_a][pos_b] != -1) {
        return memo[pos_a][pos_b];
    }

    if (a[pos_a] == b[pos_b]) {
        return memo[pos_a][pos_b] = 1 + countLCS(a, b, pos_a-1, pos_b-1);
    }

    return memo[pos_a][pos_b] = max(countLCS(a, b, pos_a-1, pos_b), countLCS(a, b, pos_a, pos_b-1));
}

int main() {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);
        memset(memo, -1, sizeof memo);

        cout << countLCS(a, b, a.size()-1, b.size()-1) << endl;
    }
}