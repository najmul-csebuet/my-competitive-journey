// https: // codeforces.com/problemset/problem/2195/A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
public:
  void solve(vi nums) {
    // check if nums contsains 67
    bool found = false;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 67) {
        found = true;
        break;
      }
    }

    if (found)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

private:
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int testCases = 1;
  // Disable if test cases count is not given
  cin >> testCases;
  while (testCases--) {
    // take input here
    int n;
    vi nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums.push_back(x);
    }
    // call solve function
    Solution s;
    s.solve(nums);
  }
  return 0;
}