#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC
void solve(vi& a) {
  int oddCount = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] % 2 == 1) {
      oddCount++;
    }
  }

  if (oddCount > 0 and oddCount < a.size()) {
    sort(a.begin(), a.end());
  }

  // print sorted array
  cout << a[0];
  for (int i = 1; i < a.size(); ++i) {
    cout << " " << a[i];
  }
  cout << endl;
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
    vi a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    // call solve function
    solve(a);
  }
  return 0;
}