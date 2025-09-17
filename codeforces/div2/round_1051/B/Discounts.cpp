#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &products, vector<int> &vouchers) {
  long long cost = 0;
  // iterate over vouchers
  int i = 0, j;
  for (int v : vouchers) {
    j = i + v - 1;
    j = min(j, (int)products.size() - 1);

    if (j - i + 1 < v) {
      // need to buy single by single
      j = i - 1;
      break;
    }

    if (i == j) {
      // no cost
      i = j + 1;
      continue;
    }

    // sum up cost from i to j - 1
    for (int a = i; a < j; a++) {
      cost += products[a];
    }
    i = j + 1;
  }

  // sum from j to n - 1
  for (int a = j + 1; a < (int)products.size(); a++) {
    cost += products[a];
  }
  cout << cost << endl;
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
    int n, k;
    cin >> n >> k;
    vector<int> products(n), vouchers(k);
    for (int i = 0; i < n; i++) {
      cin >> products[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> vouchers[i];
    }
    // sort products big to small
    sort(products.begin(), products.end(), greater<int>());
    // sort vouchers small to big
    sort(vouchers.begin(), vouchers.end());
    solve(products, vouchers);
  }
  return 0;
}