#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M, Q, R;
    scanf("%d %d", &N, &M);
    vector<string> matrixS(N);
    
    for (int i = 0; i < N; i++) {
        cin >> matrixS[i];
    }
    
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int count = 0;
        string S;
        cin >> R >> S;
        
        for (int j = 0; j < M; j++) {
            if (matrixS[R-1][j] != S[j]) {
                int searchRowUp = R - 2;
                if (searchRowUp < 0) {
                    searchRowUp = N-1;
                }
                int tempCountUp = 1;
                while (searchRowUp != R - 1) {
                    if (matrixS[searchRowUp][j] == S[j]) {
                        break;
                    }
                    if (searchRowUp-1 < 0) {
                        searchRowUp = N-1;
                    } else {
                        searchRowUp--;
                    }
                    tempCountUp++;
                }
                
                int searchRowDown = R;
                if (searchRowDown >= N) {
                    searchRowDown = 0;
                }
                int tempCountDown = 1;
                while (searchRowDown != R - 1) {
                    if (matrixS[searchRowDown][j] == S[j]) {
                        break;
                    }
                    if (searchRowDown+1 >= N) {
                        searchRowDown = 0;
                    } else {
                        searchRowDown++;
                    }
                    tempCountDown++;
                }
                
                if (searchRowUp == R - 1 && searchRowDown == R - 1) {
                    count = -1;
                    break;
                } else {
                    count+=min(tempCountUp, tempCountDown);
                }
                // cout << tempCountUp << ' ' << tempCountDown << endl;
            }
        }
        
        cout << count << endl;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}