#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // 1, 1, 2, 3, 3
    int lastFilled = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[lastFilled] < nums[i]) {
        nums[++lastFilled] = nums[i];
      }
    }
    return lastFilled + 1;
  }
};

struct TestCase {
  vector<int> nums;
  int uniqueCount;
};

int main() {
  // make test cases with array and answer as pairs
  vector<TestCase> testCases = {
      {{1, 1, 2}, 2},
      {{1, 1, 2, 3, 3}, 3},
      {{1, 1, 1, 2, 3, 3}, 3},
      {{1, 1, 1, 2, 3, 3, 4, 4, 4}, 4},
      {{1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5}, 5},
  };

  int testCase = 0;

  for (auto tc : testCases) {
    ++testCase;
    Solution s;
    int result = s.removeDuplicates(tc.nums);

    cout << "Test case #" << testCase << ": ";
    if (result != tc.uniqueCount) {
      cout << "FAILED" << "\n";
      cout << "expected: " << tc.uniqueCount << "\n";
      cout << "actual: " << result << "\n";
      continue;
    }

    // print like test case 1: passed
    cout << "Passed" << "\n";
  }
  cout << "\n";
  return 0;
}