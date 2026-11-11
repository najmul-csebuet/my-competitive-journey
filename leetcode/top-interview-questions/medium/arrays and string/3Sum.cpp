// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/backtracking/776/

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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vvi result;
    for (int i = 0; i < sz(nums); ++i) {
      for (int j = i + 1; j < sz(nums); ++j) {
        for (int k = j + 1; k < sz(nums); ++k) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            result.pb({nums[i], nums[j], nums[k]});
            cout << nums[i] << ", " << nums[j] << ", " << nums[k] << endl;
          }
        }
      }
    }
    return result;
  }
};

struct TestCase {
  vi input;
  vvi ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}};
  TestCase case2 = {{0, 1, 1}, {}};
  TestCase case3 = {{0, 0, 0}, {{0, 0, 0}}};

  return {case1, case2, case3};
}

int main() {
  auto testCases = getTests();
  int successCount = 0;
  Solution solution;

  rep0(sz(testCases)) {
    auto& tc = testCases[i];
    auto result = solution.threeSum(tc.input);

    sort(all(tc.ans));
    sort(all(result));

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