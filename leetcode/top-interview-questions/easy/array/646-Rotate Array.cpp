#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  void rotate(vector<int>& nums, int k) {
    // k is the number of elements to rotate
    k = k % nums.size();
    // reverse nums
    reverse(nums.begin(), nums.end());
    // now reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // reverse now last nums.size() - k elements
    reverse(nums.begin() + k, nums.end());
  }
};

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    if(k == 0) {
      return;
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

struct TestCase {
  vector<int> nums;
  int k;
  vector<int> ans;
};

int main() {
  vector<TestCase> testCases = {
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}}};

  for (auto tc : testCases) {
    Solution s;
    s.rotate(tc.nums, tc.k);
    bool flag = true;
    for (int i = 0; i < tc.nums.size(); ++i) {
      if (tc.nums[i] != tc.ans[i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Passed" << endl;
    } else {
      cout << "Failed" << endl;
    }
  }
  return 0;
}