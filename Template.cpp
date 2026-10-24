#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
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
  void solve() {}

 private:
};

// For Codeforces input output handling
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int testCases = 1;
  // Disable if test cases count is not given
  cin >> testCases;
  while (testCases--) {
    // take input here

    // call solve function
    Solution s;
    s.solve();
  }
  return 0;
}

// For leetcode

/*
struct TestCase {
  vi nums;
  vi ans;
};

int main() {
  vector<TestCase> testCases = {
        {{0,1,0,3,12}, {1,3,12,0,0}},
        {{0}, {0}}
    };

  Solution solution;

  for (auto& tc : testCases) {
    vi result = solution.solve();

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}
*/