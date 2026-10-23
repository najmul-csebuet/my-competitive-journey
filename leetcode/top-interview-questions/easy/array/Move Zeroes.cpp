// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

class Solution {
 public:
  void moveZeroes(vi& nums) {
    int left = 0;
    rep(right, 0, sz(nums)) {
      if (nums[right] != 0) {
        // if (left != right) {
        //   nums[left] = nums[right];
        //   nums[right] = 0;
        // }
        // Using swap (cleanest & most idiomatic)
        swap(nums[left], nums[right]);
        ++left;
      }
    }
  }
};

struct TestCase {
  vi nums;
  vi ans;
};

int main() {
  vector<TestCase> testCases = {{{0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}},
                                {{0}, {0}}};

  Solution solution;

  for (auto& tc : testCases) {
    solution.moveZeroes(tc.nums);

    if (tc.nums == tc.ans) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}