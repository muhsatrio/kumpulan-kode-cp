// When there are two DNA sequences, we will measure how similar these two are.

// A sequence of DNA is a string consisting of ‘A’, ‘C’, ‘G’, and ‘T’. A similar degree of two DNA sequences can be determined by LCS.

// This is the longest common subsequence.

// Given two DNA sequences, print out the length of the LCS of the two.

// [Enter]

// The number of test cases in the first line is given T. (1 ≤ T ≤ 10)

// Each test case contains a sequence of DNA in the first and second lines. The length of the DNA sequence is less than 1,000.

// [Output]

// In each test case, print the test case number “#(TC)” and print the LCS length of the two DNA sequences.
// Input
// 1
// ACGT
// AGCT

// Output
// #1 3 	The answer to test case one

#include <iostream>
#include <vector>

using namespace std;

int countDP(int i, int j, vector<vector<int>>& memo, string& a, string &b) {
  if (i >= a.length() || j >= b.length()) return 0;
  
  if (memo[i][j] != -1) return memo[i][j];
  
  if (a[i] == b[j]) {
    return memo[i][j] = 1 + countDP(i+1, j+1, memo, a, b);
  } else {
    return memo[i][j] = max(countDP(i+1, j, memo, a, b), countDP(i, j+1, memo, a, b)); 
  }
}

int main() 
{
  int t;
  
  cin >> t;
  
  while (t--) {
    string a;
    string b;
    cin >> a;
    cin >> b;
    
    vector<vector<int>> memo(a.length(), vector<int>(b.length(), -1));
    
    cout << countDP(0, 0, memo, a, b) << endl;
  }
  return 0;
}
