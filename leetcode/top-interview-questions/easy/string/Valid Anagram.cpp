// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/882/

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
  // unicode chars
  bool isAnagram(string s, string t) {
    // first lets assume all english letters
    vi sMap(123, 0), tMap(123, 0);
    rep0(sz(s)) sMap[s[i]]++;
    rep0(sz(t)) tMap[t[i]]++;

    return sMap == tMap;
  }

  // from web
  bool isAnagramWeb(string s, string t) {
    unordered_map<char, int> count;

    // Count the frequency of characters in string s
    for (auto x : s) {
      count[x]++;
    }

    // Decrement the frequency of characters in string t
    for (auto x : t) {
      count[x]--;
    }

    // Check if any character has non-zero frequency
    for (auto x : count) {
      if (x.second != 0) {
        return false;
      }
    }

    return true;
  }
};

struct TestCase {
  string s, t;
  bool ans;
};

int main() {
  vector<TestCase> testCases = {{"anagram", "nagaram", true},
                                {"rat", "car", false}};

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.isAnagram(tc.s, tc.t);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}

// 0174 777 2575, Mirpur 1