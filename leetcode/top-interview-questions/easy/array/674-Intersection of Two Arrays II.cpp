#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    // make sure to build the frequency map for smaller array first
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }

    // build frequency map for nums1 using unordered_map
    unordered_map<int, int> freq1;
    for (int num : nums1) {
      freq1[num]++;
    }

    // now iterate over nums2 and check if the frequency of each element is
    // greater than 0, if so add it and decrement the frequency
    vector<int> ans;
    // if space is super critical, use reserve to avoid reallocation
    ans.reserve(nums1.size());

    for (int num : nums2) {
      if (freq1[num] > 0) {
        ans.push_back(num);
        freq1[num]--;
      }
    }
    return ans;
  }
};

int main() { return 0; }