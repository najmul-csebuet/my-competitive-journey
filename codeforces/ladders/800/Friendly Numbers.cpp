// https://codeforces.com/problemset/problem/2197/A

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC in 1 hour and 43 minutes
class Solution {
public:
  void solve(int x) {
    if (x % 9 != 0) {
      cout << 0 << endl;
      return;
    }

    // now x is divisible by 9
    int a = x + 1;
    while (true) {
      int s = a - digitSum(a);
      if (s < x) {
        a++;
        continue;
      }

      if (s == x) {
        cout << 10 << endl;
        return;
      }
      break;
    }
    cout << 0 << endl;
  }

private:
  int digitSum(int x) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  }
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
    int x;
    cin >> x;
    // call solve function
    Solution s;
    s.solve(x);
  }
  return 0;
}