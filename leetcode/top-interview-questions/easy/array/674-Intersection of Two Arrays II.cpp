#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
#define pb push_back

class Solution0 {
 public:
  vi intersect(vi& nums1, vi& nums2) {
    // make sure to build the frequency map for smaller array first
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }

    // build frequency map for nums1 using unordered_map
    umii freq1;
    for (int num : nums1) {
      freq1[num]++;
    }

    // now iterate over nums2 and check if the frequency of each element is
    // greater than 0, if so add it and decrement the frequency
    vi ans;
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

class Solution {
 public:
  vi intersect(vi& nums1, vi& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }

    mii freqMap;
    for (int a : nums1) {
      freqMap[a]++;
    }

    vi result;
    for (int a : nums2) {
      if (freqMap[a] > 0) {
        result.pb(a);
        freqMap[a]--;
      }
    }
    return result;
  }
};

struct TestCase {
  vi nums1, nums2;
  vi ans;
};

int main() {
  vector<TestCase> testCases = {{{1, 2, 2, 1}, {2, 2}, {2, 2}},
                                {{4, 9, 5}, {9, 4, 9, 8, 4}, {4, 9}}};

  Solution solution;

  for (auto& tc : testCases) {
    vi result = solution.intersect(tc.nums1, tc.nums2);

    sort(result.begin(), result.end());
    sort(tc.ans.begin(), tc.ans.end());
    
    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}