// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

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
  int myAtoi(string s) {
    string filtered;

    // Skip leading whitespaces
    int i = 0, n = sz(s);
    while (i < n && isspace(s[i])) {
      ++i;
    }

    // Empty string or only whitespace
    if (i == n) return 0;

    // Determine sign
    int sign = 1;
    if (s[i] == '-') {
      sign = -1;
      ++i;
    } else if (s[i] == '+') {
      ++i;
    }

    // INT_MAX = +2147483647
    // INT_MIN = -2147483648
    int ans = 0;
    while (i < sz(s) && isdigit(s[i])) {
      int d = s[i++] - '0';
      d *= sign;

      if (ans >= 0) {
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > 7)) {
          ans = INT_MAX;
          break;
        }
      } else {
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && d == -9)) {
          ans = INT_MIN;
          break;
        }
      }

      ans = 10 * ans + d;
    }
    return ans;
  }

  int myAtoiClaudeAI(string s) {
    int i = 0, n = sz(s);
    while (i < n && s[i] == ' ') ++i;

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
      if (s[i] == '-') sign = -1;
      ++i;
    }

    int ans = 0;

    while (i < n && isdigit(s[i])) {
      int d = s[i] - '0';
      // ans * 10 + d > INT_MAX
      // ans > (INT_MAX - d) / 10
      if (ans > (INT_MAX - d) / 10) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }
      ans = ans * 10 + d;
      ++i;
    }

    return ans * sign;
  }
};

struct TestCase {
  string input;
  int ans;
};

vector<TestCase> getTests() {
  TestCase case0 = {"2147483646", 2147483646};
  TestCase case1 = {"42", 42};
  TestCase case2 = {" -042", -42};
  TestCase case3 = {"1337c0d3", 1337};
  TestCase case4 = {"0-1", 0};
  TestCase case5 = {"words and 987", 0};
  TestCase case6 = {"", 0};
  TestCase case7 = {"   ", 0};
  TestCase case8 = {"+", 0};
  TestCase case9 = {"-", 0};
  TestCase case10 = {"+-12", 0};
  TestCase case11 = {"4193 with words", 4193};
  TestCase case12 = {"-91283472332", INT_MIN};
  TestCase case13 = {"91283472332", INT_MAX};
  TestCase case14 = {"2147483647", INT_MAX};
  TestCase case15 = {"2147483648", INT_MAX};
  TestCase case16 = {"-2147483648", INT_MIN};
  TestCase case17 = {"-2147483649", INT_MIN};

  return {case0,  case1,  case2,  case3,  case4,  case5,
          case6,  case7,  case8,  case9,  case10, case11,
          case12, case13, case14, case15, case16, case17};
}

int main() {
  auto testCases = getTests();

  Solution solution;

  for (auto& tc : testCases) {
    // auto result = solution.myAtoi(tc.input);
    auto result = solution.myAtoiClaudeAI(tc.input);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}