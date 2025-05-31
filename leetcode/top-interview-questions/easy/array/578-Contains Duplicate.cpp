#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
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
  bool containsDuplicate(vector<int> &nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
  }
};

// another solution
class Solution3 {
public:
  bool containsDuplicate(vector<int> &nums) {
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
  bool containsDuplicate(vector<int> &nums) {
    // use a set to store the elements
    // then check if the size of the set is less than the size of the vector
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() < nums.size();
  }
};

// now use unordered_set and find method
class Solution5 {
public:
  bool containsDuplicate(vector<int> &nums) {
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

// now use unordered_set and count method
class Solution6 {
public:
  bool containsDuplicate(vector<int> &nums) {
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
  bool containsDuplicate(vector<int> &nums) {
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

int main() { return 0; }