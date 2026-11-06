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
    rep(prefixLength, 0, sz(strs[0])) {
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

  TestCase case4 = {{"a"}, "a"};        // single string
  TestCase case5 = {{""}, ""};          // single empty string
  TestCase case6 = {{"", "b"}, ""};     // empty string in the list
  TestCase case7 = {{"ab", "a"}, "a"};  // later string is a prefix of the first
  TestCase case8 = {{"a", "ab"}, "a"};  // first string is the prefix
  TestCase case9 = {{"same", "same", "same"}, "same"};
  TestCase case10 = {{"abc", "abd", "abx", "ab"},
                     "ab"};  // shortest string is last
  return {case1, case2, case3, case4, case5,
          case6, case7, case8, case9, case10};
}

int main() {
  auto testCases = getTests();
  int successCount = 0;
  Solution solution;

  rep0(sz(testCases)) {
    auto& tc = testCases[i];
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