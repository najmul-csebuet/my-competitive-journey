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

    // Whitespace
    int i;
    for (i = 0; i < sz(s); ++i) {
      if (!isspace(s[i])) {
        break;
      }
    }
    // i now points to first non blank char
    if (isalpha(s[i])) {
      return 0;
    }

    int sign;
    if (s[i] == '-') {
      sign = -1;
      ++i;
    } else if (s[i] == '+') {
      sign = +1;
      ++i;
    } else if (isalnum(s[i]))
      sign = +1;

    int ans = 0;
    while (i < sz(s)) {
      if (isalpha(s[i])) {  // if it is any letter, stop
        break;
      }

      if (!isalnum(s[i])) {  // if not number, stop
        break;
      }

      int d = s[i++] - '0';
      if (sign == -1) d = -d;

      if (sign == 1) {
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > 7)) {
          ans = INT_MAX;
          break;
        }
      } else {
        // -1, negative number
        if (ans > 0) ans = -ans;
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && d == -9)) {
          ans = INT_MIN;
          break;
        }
      }

      ans = 10 * ans + d;
    }
    return ans;
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

  return {case0, case1, case2, case3, case4, case5};
  // return {case2};
}

int main() {
  auto testCases = getTests();

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.myAtoi(tc.input);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}