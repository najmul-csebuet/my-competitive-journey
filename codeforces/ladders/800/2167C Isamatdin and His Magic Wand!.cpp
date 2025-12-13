#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve(vi& a) {
  int firstEmptyIndex = 0;
  while (true) {
    if (firstEmptyIndex == a.size()) {
      // no place left to swap
      break;
    }
    // find min element index and check if we can place it at the first position
    int minIndex = firstEmptyIndex;
    for (int i = firstEmptyIndex + 1; i < a.size(); ++i) {
      if (a[i] < a[minIndex]) {
        minIndex = i;
      }
    }

    if (a[firstEmptyIndex] <= a[minIndex]) {
      // they are already lexicographically sorted
      firstEmptyIndex++;
      continue;
    }

    if (a[firstEmptyIndex] % 2 == a[minIndex] % 2) {
      // parity same so no swap possible
      firstEmptyIndex++;
      continue;
    }

    swap(a[firstEmptyIndex], a[minIndex]);
    firstEmptyIndex++;
  }

  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
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