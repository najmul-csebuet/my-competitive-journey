// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // 1. Reversal approach (Optimal O(1) space)
  void rotateWithReversal(vector<int>& nums, int k) {
    if (nums.empty()) return;
    int n = nums.size();
    k %= n;
    if (k == 0) return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }

  // 2. Additional memory approach (O(n) space)
  void rotateWithAdditionalMemory(vector<int>& nums, int k) {
    if (nums.empty()) return;
    int n = nums.size();
    k %= n;  // Crucial to prevent unsigned underflow with nums.size()
    if (k == 0) return;

    vector<int> newNums(n);
    int i = 0;

    // Copy the last k elements to the front
    for (int j = n - k; j < n; ++j) {
      newNums[i++] = nums[j];
    }
    // Copy the remaining elements
    for (int j = 0; j < n - k; ++j) {
      newNums[i++] = nums[j];
    }

    nums = move(newNums);  // Efficient assignment
  }

  // 3. Cyclic replacements approach (O(1) space) - Renamed from
  // CyclicDependency
  void rotateWithCyclicReplacements(vector<int>& nums, int k) {
    if (nums.empty()) return;
    int n = nums.size();
    k %= n;
    if (k == 0) return;

    int count = 0;
    for (int start = 0; count < n; ++start) {
      int current = start;
      int prev = nums[start];
      do {
        int next_idx = (current + k) % n;
        swap(prev, nums[next_idx]);
        current = next_idx;
        count++;
      } while (start != current);
    }
  }

  void rotateWithCyclicReplacementsPractice(vector<int>& nums, int k) {
    if (nums.empty()) return;
    int totalNumbers = nums.size();
    k %= totalNumbers;
    if (k == 0) return;

    int correctlyMoved = 0;
    for (int cycleStartIndex = 0; correctlyMoved < totalNumbers;
         ++cycleStartIndex) {
      int currentIndex = cycleStartIndex;
      int prev = nums[cycleStartIndex];

      do {
        int nextIndex = (currentIndex + k) % totalNumbers;
        swap(nums[nextIndex], prev);

        currentIndex = nextIndex;
        correctlyMoved++;
      } while (cycleStartIndex != currentIndex);
    }
  }
};

struct TestCase {
  vector<int> nums;
  int k;
  vector<int> ans;
};

void checkIfArraySame(const vector<int>& nums, const vector<int>& ans) {
  // std::vector natively supports the == operator
  if (nums == ans) {
    cout << "Passed" << endl;
  } else {
    cout << "Failed" << endl;
  }
}

int main() {
  vector<TestCase> testCases = {
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}}};

  Solution s;

  cout << "--- Testing rotateWithReversal ---" << endl;
  for (const auto& tc : testCases) {
    vector<int> numsCopy = tc.nums;
    s.rotateWithReversal(numsCopy, tc.k);
    checkIfArraySame(numsCopy, tc.ans);
  }

  cout << "\n--- Testing rotateWithAdditionalMemory ---" << endl;
  for (const auto& tc : testCases) {
    vector<int> numsCopy = tc.nums;
    s.rotateWithAdditionalMemory(numsCopy, tc.k);
    checkIfArraySame(numsCopy, tc.ans);
  }

  cout << "\n--- Testing rotateWithCyclicReplacements ---" << endl;
  for (const auto& tc : testCases) {
    vector<int> numsCopy = tc.nums;
    s.rotateWithCyclicReplacements(numsCopy, tc.k);
    checkIfArraySame(numsCopy, tc.ans);
  }

  cout << "\n--- Testing rotateWithCyclicReplacementsPractice ---" << endl;
  for (const auto& tc : testCases) {
    vector<int> numsCopy = tc.nums;
    s.rotateWithCyclicReplacementsPractice(numsCopy, tc.k);
    checkIfArraySame(numsCopy, tc.ans);
  }

  return 0;
}

/*
 1: Yellow cross
=================
To make yellow cross:
First start with yellow dot, then half plus, then yellow minus and set it as
horizontal for cross. then make it cross. Using same formula: F, R, U, R', U',
F'

 2: Fix middle
================
Fix middle after yellow cross:
1. Set 1 matched middle at rear/back side and another one at right side
2. Then do these moves: R, U, R', U,     R, U2, R', U
3. Check if all 4 middles are matched.

 3: Match the corners
======================
Now match the corners:
1. See if any one corner is correctly positioned. Keep that at your top right
front side
2. Apply: L', U, R, U', L, U, R', U',

 4: Finishing
==============
Finishing:
1. For each not placed corner: Keep that at your right bottom front side [Yellow
layer will be down side]
2. Apply in loop until this corner is fixed: R, U, R', U'

Once this is fixed, apply D to bring another misplaced corner. then apply above
step 2

*/