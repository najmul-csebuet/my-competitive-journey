// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution0 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a map to store the frequency of each element
    // then check if any number appears more than once
    map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    for (auto [num, freq] : freq) {
      if (freq > 1) {
        return true;
      }
    }
    return false;
  }
};

// another solution
class Solution2 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
  }
};

// Most space efficient solution, no extra space at all
// another solution
class Solution3 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // first sort the vector
    sort(nums.begin(), nums.end());
    // then check if the adjacent elements are equal
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

// now use unordered_set
class Solution4 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
  }
};

// Best Solution
// now use unordered_set and find method
class Solution5 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    unordered_set<int> s;
    for (int num : nums) {
      if (s.find(num) != s.end()) {
        return true;
      }
      s.insert(num);
    }
    return false;
  }
};

// buggy as count will always return 1
// now use unordered_set and count method
class Solution6 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    unordered_set<int> s;
    for (int num : nums) {
      if (s.count(num) > 1) {
        return true;
      }
      s.insert(num);
    }
    return false;
  }
};

// now use unordered_map
class Solution7 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    // use a map to store the frequency of each element
    // then check if any number appears more than once
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    for (auto [num, freq] : freq) {
      if (freq > 1) {
        return true;
      }
    }
    return false;
  }
};

class Solution {
 public:
  // Best O(n) approach but uses extra memory
  // unordered_set incremental insertion aproach
  bool containsDuplicateUsingSet(vector<int>& nums) {
    unordered_set<int> s;
    for (int a : nums) {
      if (s.find(a) != s.end()) {
        return true;
      }
      s.insert(a);
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