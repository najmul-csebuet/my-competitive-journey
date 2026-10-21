// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // Best O(n) approach but uses extra memory
  // unordered_set incremental insertion aproach
  bool containsDuplicateUsingSet(vector<int>& nums) {
    unordered_set<int> s;
    for (int a : nums) {
      if (!s.insert(a).second) {
        return true;
      }

      // if (s.find(a) != s.end()) {
      //   return true;
      // }
      // s.insert(a);
    }

    return false;
  }

  // O(nlgn) approach but uses no extra memory
  // uses sorting and then traversing
  bool containsDuplicateUsingSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) {
        return true;
      }
    }
    return false;
  }
};

struct TestCase {
  vector<int> nums;
  bool ans;
};

int main() {
  vector<TestCase> testCases = {
      {{1, 2, 3, 1}, true},
      {{1, 2, 3, 4}, false},
      {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},
  };

  Solution solution;

  for (auto& tc : testCases) {
    bool result = solution.containsDuplicateUsingSet(tc.nums);
    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  for (auto& tc : testCases) {
    bool result = solution.containsDuplicateUsingSorting(tc.nums);
    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}