// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/

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
// Note: If you nest these, use different variable names or stick to the
// 3-parameter version.
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(n) for (int i = 0; i < (n); ++i)
#define repr(i, a, b) for (int i = (a) - 1; i >= (b); --i)

class Solution {
 public:
  vi twoSum(vi& nums, int target) {
    sort(all(nums));

    vi result;

    rep0(sz(nums)) {
      int remaining = target - nums[i];
      //   bool found = binary_search(all(nums), remaining);
      auto it = lower_bound(all(nums), remaining);
      if (it != nums.end()) {
        // found
        int index = distance(nums.begin(), it);
        if (i != index) {
          result = {i, index};
          break;
        }
      }
    }

    return result;
  }
};

// For leetcode

struct TestCase {
  vi nums;
  int target;
  vi ans;
};

int main() {
  vector<TestCase> testCases = {
      {{2, 7, 11, 15}, 9, {0, 1}}, {{3, 2, 4}, 6, {1, 2}}, {{3, 3}, 6, {0, 1}}};

  Solution solution;

  for (auto& tc : testCases) {
    auto result = solution.twoSum(tc.nums, tc.target);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed: ";
      rep0(sz(tc.nums)) cout << tc.nums[i] << ", ";
      cout << endl;
      cout << "Target: " << tc.target << ", Found indexes = " << result[0]
           << ", " << result[1] << endl
           << endl;
    }
  }

  return 0;
}
