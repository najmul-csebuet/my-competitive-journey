#include <bits/stdc++.h>
using namespace std;

int main() {
  int testCases;
  cin >> testCases;

  int n, m, x, y;
  while (testCases--) {
    cin >> n >> m >> x >> y;
    // read next n numbers into vector N
    // read next m numbers into vector M
    vector<int> N(n), M(m);
    for (int i = 0; i < n; i++) {
      cin >> N[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> M[i];
    }
    cout << n + m << endl;
  }
  return 0;
}
