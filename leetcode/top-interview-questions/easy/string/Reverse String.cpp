// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/879/

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
  void reverseString(vc& s) {
    rep0(sz(s) / 2) { swap(s[i], s[sz(s) - i - 1]); }
  }
};

struct TestCase {
  vc s;
  vc ans;
};

int main() {
  vector<TestCase> testCases = {
      {{'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}},
      {{'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'}}};

  Solution solution;

  for (auto& tc : testCases) {
    solution.reverseString(tc.s);

    if (tc.ans == tc.s) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}