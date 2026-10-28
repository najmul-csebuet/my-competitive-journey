// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using mii = map<int, int>;
using pii = pair<int, int>;
using umii = unordered_map<int, int>;

// Useful Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(n) for (int i = 0; i < (n); ++i)
// Note: If you nest these, use different variable names or stick to the
// 3-parameter version.
#define repr(i, a, b) for (int i = (a) - 1; i >= (b); --i)

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = sz(matrix);
    rep(i, 0, n) {
      rep(j, 0, n) { swap(matrix[i][j], matrix[j][n - 1 - i]); }
    }
  }
};

// For leetcode

struct TestCase {
  vvi matrix;
  vvi ans;
};

int main() {
  vvi matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vvi matrix1Output = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  vvi matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  vvi matrix2Output = {
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

  vector<TestCase> testCases = {{matrix1, matrix1Output},
                                {matrix2, matrix2Output}};

  Solution solution;

  for (auto& tc : testCases) {
    solution.rotate(tc.matrix);

    if (tc.matrix == tc.ans) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}

/*
0,0 --> 0,3
0,1 --> 1,3
0,2 --> 2,3
0,3 --> 3,3

1,0 --> 0,2
1,1 --> 1,2
1,2 --> 2,2
1,3 --> 3,2

i,j --> j,n-1-i
*/