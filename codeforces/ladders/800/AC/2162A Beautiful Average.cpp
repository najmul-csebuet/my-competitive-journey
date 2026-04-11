#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC
void solve(vi& a) {
  // find max value in array
  int max = *max_element(a.begin(), a.end());
  cout << max << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif

  int testCases;
  cin >> testCases;

  while (testCases--) {
    // take input here
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // call solve function
    solve(a);
  }
  return 0;
}