#include <iostream>

using namespace std;

const int coinValue[5] = {50, 25, 10, 5, 1};

int memo[5][7490];

int countWays(int type, int value) {
    if (value == 0) {
        return 1;
    }
    if (value < 0 || type == 5) {
        return 0;
    }

    int &ans = memo[type][value];

    if (ans != 0) {
        return ans;
    }

    return ans = countWays(type+1, value) + countWays(type, value - coinValue[type]);
}


int main() {
    int n;

    while (cin >> n) {
        cout << countWays(0, n) << endl;
    }
}