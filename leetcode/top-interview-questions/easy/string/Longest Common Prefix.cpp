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
    const string& first = strs[0];

    rep(i, 0, sz(first)) {
      rep(j, 1, sz(strs)) {
        if (i == sz(strs[j])) {
          return strs[j];
        }

        if (first[i] != strs[j][i]) {
          return first.substr(0, i);
        }
      }
    }
    return first;
  }
};

struct TestCase {
  string name;
  vs input;
  string ans;
};

vector<TestCase> getTests() {
  return {
      {"leetcode example 1", {"flower", "flow", "flight"}, "fl"},
      {"leetcode example 2", {"dog", "racecar", "car"}, ""},
      {"mismatch at last char", {"abb", "abc"}, "ab"},
      {"single string", {"a"}, "a"},
      {"single empty string", {""}, ""},
      {"empty string in list", {"", "b"}, ""},
      {"later string is prefix of first", {"ab", "a"}, "a"},
      {"first string is prefix of later", {"a", "ab"}, "a"},
      {"all identical", {"same", "same", "same"}, "same"},
      {"shortest string is last", {"abc", "abd", "abx", "ab"}, "ab"},
  };
}

string show(const vs& v) {
  string s = "[";
  rep(i, 0, sz(v)) {
    if (i) s += ", ";
    s += '"' + v[i] + '"';
  }
  return s + "]";
}

int main() {
  auto testCases = getTests();
  Solution solution;
  int passed = 0;

  for (auto& tc : testCases) {
    vs input = tc.input;  // copy in case the solution mutates its argument
    string result = solution.longestCommonPrefix(input);

    if (result == tc.ans) {
      ++passed;
    } else {
      cout << "FAIL: " << tc.name << "\n"
           << "  input:    " << show(tc.input) << "\n"
           << "  expected: \"" << tc.ans << "\"\n"
           << "  actual:   \"" << result << "\"\n";
    }
  }

  cout << passed << "/" << sz(testCases) << " passed\n";
  return passed == sz(testCases) ? 0 : 1;
}