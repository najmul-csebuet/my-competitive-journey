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
  int solve(int nums) {}
};

struct TestCase {
  int input;
  int ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {1, 2};
  TestCase case2 = {3, 4};
  TestCase case3 = {5, 6};

  return {case1, case2, case3};
}

int main() {
  auto testCases = getTests();

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.solve(tc.input);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}