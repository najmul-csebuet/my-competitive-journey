// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/885/

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
  int strStr(string haystack, string needle) {
    int n = sz(haystack), m = sz(needle);
    if (m == 0) {
      // standard convention, matches strstr/find
      return 0;
    }

    // try start positions where needle can fit: 0 to n - m
    rep(i, 0, n - m + 1) {
      bool found = true;
      rep(j, 0, m) {
        if (haystack[i + j] != needle[j]) {
          found = false;
          break;
        }
      }
      if (found) return i;
    }
    return -1;
  }
};

struct TestCase {
  string haystack;
  string needle;
  int ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {"sadbutsad", "sad", 0};
  TestCase case2 = {"leetcode", "leeto", -1};

  return {case1, case2};
}

int main() {
  auto testCases = getTests();
  int successCount = 0;
  Solution solution;

  rep0(sz(testCases)) {
    auto& tc = testCases[i];
    // auto result = solution.myAtoi(tc.input);
    auto result = solution.strStr(tc.haystack, tc.needle);

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