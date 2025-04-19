#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int last = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[last]) {
        nums[++last] = nums[i];
      }
    }
    return last + 1;
  }
};

int main() {
  // make test cases with array and answer as pairs
  vector<pair<vector<int>, int>> testCses = {
      {{1, 1, 2}, 2},
      {{1, 1, 2, 3, 3}, 3},
      {{1, 1, 1, 2, 3, 3}, 3},
      {{1, 1, 1, 2, 3, 3, 4, 4, 4}, 4},
      {{1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5}, 5},
  };

  int testCase = 0;

  for (auto tc : testCses) {
    ++testCase;
    Solution s;
    int result = s.removeDuplicates(tc.first);

    cout << "Test case #" << testCase << ": ";
    if (result != tc.second) {
      cout << "FAILED" << "\n";
      cout << "expected: " << tc.second << "\n";
      cout << "actual: " << result << "\n";
      continue;
    }

    // print like test case 1: passed
    cout << "Passed" << "\n";
  }
  cout << "\n";
  return 0;
}