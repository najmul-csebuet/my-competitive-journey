#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using mii = map<int, int>;
using pii = pair<int, int>;
using umii = unordered_map<int, int>;

// Useful Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(n) for (int i = 0; i < (n); ++i)
// Note: If you nest these, use different variable names or stick to the
// 3-parameter version.
#define repr(i, a, b) for (int i = (a) - 1; i >= (b); --i)

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
  vi intersectByMap(vi& nums1, vi& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersectByMap(nums2, nums1);
    }

    umii freqMap;
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

  vi intersectByMergeOnSortedArrays(vi& nums1, vi& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersectByMergeOnSortedArrays(nums2, nums1);
    }

    vi result;

    // both arrays are sorted
    int i = 0, j = 0;
    while (i < sz(nums1) && j < sz(nums2)) {
      if (nums1[i] == nums2[j]) {
        result.pb(nums1[i]);
        ++i;
        ++j;
      } else if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
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
    vi result = solution.intersectByMap(tc.nums1, tc.nums2);

    sort(result.begin(), result.end());
    sort(tc.ans.begin(), tc.ans.end());

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  for (auto& tc : testCases) {
    sort(all(tc.nums1));
    sort(all(tc.nums2));

    vi result = solution.intersectByMergeOnSortedArrays(tc.nums1, tc.nums2);

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