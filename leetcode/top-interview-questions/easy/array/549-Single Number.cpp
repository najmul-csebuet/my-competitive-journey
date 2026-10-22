// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    // do xor of all elements
    int xor_val = 0;
    for (int num : nums) {
      xor_val ^= num;
    }
    // return the xor_val
    return xor_val;
  }
};

struct TestCase {
  vector<int> nums;
  int ans;
};

int main() {
  vector<TestCase> testCases = {
      {{2, 2, 1}, 1},
      {{4, 1, 2, 1, 2}, 4},
      {{1}, 1},
  };

  Solution solution;

  for (auto& tc : testCases) {
    int result = solution.singleNumber(tc.nums);
    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}