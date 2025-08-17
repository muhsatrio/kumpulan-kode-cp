#include <iostream>
#include <vector>

using namespace std;

string lampuDanTombolSpesial(int N, vector<int> L) {
    // Write your code here
    int count = 0;
    for (int i = 1; i < N-1; i++) {
        if (L[i-1] == 0) {
            L[i-1] ^= 1;
            L[i] ^= 1;
            L[i+1] ^= 1;
            count++;
        }
    }
    
    int isAllOne = 1;
    
    for (int i = 0; i < L.size(); i++) {
        if (L[i] == 0) {
            isAllOne ^= 1;
            break;
        }
    }
    
    if (isAllOne == 1) {
        return "YES " + to_string(count);
    }
    
    return "NO -1";
}

int main() {

}
