// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/backtracking/776/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using mii = map<int, int>;
using pii = pair<int, int>;
using umii = unordered_map<int, int>;

// Useful Macros
#define vec vector
#define umap unordered_map

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(n) for (int i = 0; i < (n); ++i)
// Note: If you nest these, use different variable names or stick to the
// 3-parameter version.
#define repr(i, a, b) for (int i = (a) - 1; i >= (b); --i)

class Solution_TLE {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vvi result;
    for (int i = 0; i < sz(nums); ++i) {
      for (int j = i + 1; j < sz(nums); ++j) {
        for (int k = j + 1; k < sz(nums); ++k) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            vi temp = {nums[i], nums[j], nums[k]};
            sort(all(temp));

            bool flag = true;
            rep0(sz(result)) {
              if (result[i] == temp) {
                flag = false;
                break;
              }
            }

            if (flag) result.pb(temp);
          }
        }
      }
    }
    return result;
  }
};

class Solution_Improved_But_TLE {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vvi result;
    umii map;
    rep0(sz(nums)) map[nums[i]] = i + 1;

    for (int i = 0; i < sz(nums); ++i) {
      for (int j = i + 1; j < sz(nums); ++j) {
        int gap = 0 - (nums[i] + nums[j]);
        if (!map[gap] || map[gap] == i + 1 || map[gap] == j + 1) continue;

        vi temp = {nums[i], nums[j], gap};
        sort(all(temp));

        bool flag = true;
        rep0(sz(result)) {
          if (result[i] == temp) {
            flag = false;
            break;
          }
        }

        if (flag) result.pb(temp);
      }
    }
    return result;
  }
};

class Solution_Still_TLE_With_TwoSum {
  vvi twoSum(vi& nums, int firstIndex, int target) {
    vvi result;
    umii seen;
    for (int i = 0; i < sz(nums); ++i) {
      // check if current pair has matched with first number's index
      if (i == firstIndex || seen[target - nums[i]] == firstIndex + 1) {
        continue;
      }

      if (seen[target - nums[i]]) {
        vi temp = {nums[firstIndex], nums[i], target - nums[i]};
        sort(all(temp));
        result.pb(temp);
      } else {
        seen[nums[i]] = i + 1;
      }
    }
    return result;
  }

 public:
  vvi threeSum(vi& nums) {
    vvi result;
    rep(i, 0, sz(nums)) {
      int target = -nums[i];
      vvi twosum = twoSum(nums, i, target);
      rep(i, 0, sz(twosum)) {
        bool flag = true;
        rep(j, 0, sz(result)) {
          if (result[j] == twosum[i]) {
            flag = false;
            break;
          }
        }
        if (flag) result.pb(twosum[i]);
      }
    }
    return result;
  }
};

class Solution1 {
  vvi twoSum(vi& nums, int firstIndex, int target) {
    vvi result;
    umii seen;
    rep(i, 0, sz(nums)) {
      // if (i == firstIndex || (i > 0 && nums[i - 1] == nums[i])) {
      //   continue;  // already explored this number
      // }
      int d = target - nums[i];
      if (seen[d] && (i != firstIndex) && (seen[d] - 1) != firstIndex) {
        vi temp = {nums[firstIndex], nums[i], d};
        sort(all(temp));
        result.pb(temp);
      } else {
        seen[nums[i]] = i + 1;
      }
    }
    return result;
  }

 public:
  vvi threeSum(vi& nums) {
    vvi result;
    sort(all(nums));
    rep(i, 0, sz(nums) - 2) {
      // if (i > 0 && nums[i - 1] == nums[i]) {
      //   // check if this number is already explored for triplet searching
      //   continue;
      // }

      int target = -nums[i];
      vvi resp = twoSum(nums, i, target);
      for (auto& a : resp) {
        bool flag = true;
        for (auto& b : result) {
          if (a == b) {
            // duplicate
            flag = false;
            break;
          }
        }
        if (flag) {
          result.pb(a);
        }
      }
    }
    return result;
  }
};

class Solution {
 public:
  vvi threeSum(vi& nums) {
    vvi result;
    sort(all(nums));
    rep(i, 0, sz(nums)) {
      int a = nums[i];

      if (a > 0) {
        break;
      }

      if (i > 0 && a == nums[i - 1]) {
        continue;
      }

      int left = i + 1, right = sz(nums) - 1;
      
      while (left < right) {
        int b = nums[left];
        int c = nums[right];
        if (a + b + c == 0) {
          // found a triple
          result.pb({a, b, c});
          ++left;
          --right;
        } else if (a + b + c < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return result;
  }
};

struct TestCase {
  vi input;
  vvi ans;
};

vector<TestCase> getTests() {
  TestCase case1 = {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}};
  TestCase case2 = {{0, 1, 1}, {}};
  TestCase case3 = {{0, 0, 0}, {{0, 0, 0}}};

  return {case1, case2, case3};
}

int main() {
  auto testCases = getTests();
  int successCount = 0;
  Solution solution;

  rep0(sz(testCases)) {
    auto& tc = testCases[i];
    auto result = solution.threeSum(tc.input);

    sort(all(tc.ans));
    sort(all(result));

    if (tc.ans == result) {
      ++successCount;
    } else {
      cout << "Failed Test case: " << i + 1 << endl;
    }
  }

  if (successCount == sz(testCases)) {
    cout << "\n\nAll passed!\n\n";
  }

  return 0;
}

/*

Raw:    -1,  0,  1, 2, -1, -4
Sorted: -4, -1, -1, 0,  1,  2
*/