#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve(vi &a) {
  vi ans;
  int minimum = a[0];
  for (int i = 1; i < a.size(); i++) {
    if (minimum > a[i]) {
      minimum = a[i];
      continue;
    }

    // skip if next items are greater than minimum
    while (i < a.size() && a[i] >= minimum) {
      ans.push_back(i + 1);
      i++;
    }
    minimum = a[i];
  }
  // print ans vector
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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