#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
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

int main() { return 0; }