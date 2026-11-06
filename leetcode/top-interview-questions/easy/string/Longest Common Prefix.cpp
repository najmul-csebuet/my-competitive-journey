// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/887/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
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
  string longestCommonPrefix(vs& strs) {
    if (sz(strs) == 1) {
      return strs[0];
    }

    rep(prefixLength, 0, sz(strs[0])) {
      if (sz(strs[0]) == prefixLength) {
        return strs[0];
      }

      char ch = strs[0][prefixLength];

      rep(j, 1, sz(strs)) {
        if (sz(strs[j]) == prefixLength) {
          return strs[j];
        }

        if (ch != strs[j][prefixLength]) {
          return strs[0].substr(0, prefixLength);
        }
      }
    }
    return strs[0];
  }
};

struct TestCase {
  vs input;
  string ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {{"flower", "flow", "flight"}, "fl"};
  TestCase case2 = {{"dog", "racecar", "car"}, ""};
  TestCase case3 = {{"abb", "abc"}, "ab"};

  // return {case3};
  return {case1, case2, case3};
}

int main() {
  auto testCases = getTests();
  int successCount = 0;
  Solution solution;

  rep0(sz(testCases)) {
    auto& tc = testCases[i];
    // auto result = solution.myAtoi(tc.input);
    auto result = solution.longestCommonPrefix(tc.input);

    if (tc.ans == result) {
      ++successCount;
    } else {
      cout << "Failed Test case: " << i + 1 << endl;
    }
  }

  if (successCount == sz(testCases)) {
    cout << "\n\nAll passed!\n\n";
  }

  return 0;
}