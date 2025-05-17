#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    // k is the number of elements to rotate
  }
};

void test(vector<int> &nums, int k, vector<int> &ans) {
  Solution s;
  s.rotate(nums, k);
  // check if nums and ans are equal
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != ans[i]) {
      cout << "FAILED" << "\n";
      // print vectors
      cout << "nums: ";
      for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
      }
      cout << "\n";
      cout << "ans: ";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
      break;
    }
  }
}

int main() {
  int k = 3;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  vector<int> ans = {5, 6, 7, 1, 2, 3, 4};
  test(nums, k, ans);
  return 0;
}