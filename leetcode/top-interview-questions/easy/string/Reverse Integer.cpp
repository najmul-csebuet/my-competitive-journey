// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/880/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
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
  int reverse(int x) {
    int ans = 0;
    while (x != 0) {
      int d = x % 10;
      x /= 10;
      // Check for overflow before it happens
      if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > 7)) return 0;
      if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && d == -9)) return 0;
      ans = 10 * ans + d;
    }
    return ans;
  }
};

struct TestCase {
  int x;
  int ans;
};

int main() {
  vector<TestCase> testCases = {
      {-123, -321}, {123, 321}, {120, 21}, {1534236469, 0}};

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.reverse(tc.x);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}