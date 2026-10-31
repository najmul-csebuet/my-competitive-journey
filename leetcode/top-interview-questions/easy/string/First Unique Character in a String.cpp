// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/881/

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
  int firstUniqChar(string s) {
    vi seen(123, 0);
    // build freq map first
    rep0(sz(s)) seen[s[i]]++;
    rep0(sz(s)) {
      if (seen[s[i]] == 1) {
        return i;  // first unique char's index
      }
    }
    return -1;
  }
};

struct TestCase {
  string s;
  int ans;
};

int main() {
  vector<TestCase> testCases = {
      {"leetcode", 0}, {"loveleetcode", 2}, {"aabb", -1}};

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.firstUniqChar(tc.s);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}