// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

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
  bool isPalindrome(string s) {
    string sf;
    rep0(sz(s)) {
      if (isalnum(s[i])) {
        sf.pb(tolower(s[i]));  // Convert to lowercase on-the-fly
      }
    }

    for (int i = 0, j = sz(sf) - 1; i < j; i++, j--) {
      if (sf[i] != sf[j]) return false;
    }
    return true;
  }
};

struct TestCase {
  string s;
  bool ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {"A man, a plan, a canal: Panama", true};
  TestCase case2 = {"race a car", false};
  TestCase case3 = {" ", true};

  return {case1, case2, case3};
}

int main() {
  auto testCases = getTests();

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.isPalindrome(tc.s);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}