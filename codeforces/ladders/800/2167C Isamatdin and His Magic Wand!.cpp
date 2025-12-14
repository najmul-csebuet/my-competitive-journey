#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve(vi &a) {
  for (int i = 0; i < a.size(); ++i) {
    // find minimum element index in the array after index i
    int min = i;
    for (int j = i + 1; j < a.size(); ++j) {
      if (a[j] < a[i] && a[j] % 2 != a[i] % 2) {
        if (a[min] > a[j])
          min = j;
      }
    }
    swap(a[i], a[min]);
  }

  // print the sorted array
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