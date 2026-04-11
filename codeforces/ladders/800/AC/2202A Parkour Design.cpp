// https://codeforces.com/problemset/problem/2202/A
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC in 21 mins 55 secs
void solve(int x, int y) {
  if (y >= 0) {
    x -= (y * 2);
  } else {
    int n = abs(y);
    x -= (n * 4);
  }

  if (x < 0 || x % 3 != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

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
    // read x and y as int
    int x, y;
    cin >> x >> y;
    // call solve function
    solve(x, y);
  }
  return 0;
}