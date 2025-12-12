#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC
void solve(int n) {
  if (n % 2 == 1) {
    cout << 0 << endl;
    return;
  }

  cout << (1 + (n / 4)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int testCases;
  cin >> testCases;

  while (testCases--) {
    // take input here
    int n;
    cin >> n;
    // call solve function
    solve(n);
  }
  return 0;
}