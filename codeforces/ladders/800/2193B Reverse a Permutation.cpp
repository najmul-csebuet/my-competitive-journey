#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void print(vi &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// AC
void solve(vi &a) {
  // Case 1: if all are in decreasing order, take no action just print as is
  // 4 3 2 1
  // 2 1
  //   bool decreasing = true;
  //   for (int i = 0; i < a.size() - 1; i++) {
  //     if (a[i] != a[i + 1] + 1) {
  //       decreasing = false;
  //       break;
  //     }
  //   }
  //   if (decreasing) {
  //     print(a);
  //     return;
  //   }

  // Case 2: max value is not at the start
  // 3 2 1 4
  if (a[0] != a.size()) {
    int max_index = max_element(a.begin(), a.end()) - a.begin();
    reverse(a.begin(), a.begin() + max_index + 1);
  } else {
    // Case 3
    // 4 3 1 2
    // 3 1 2
    // skip until decreasing stops
    int dec_stop = -1;
    for (int i = 0; i < a.size() - 1; i++) {
      if (a[i] != a[i + 1] + 1) {
        dec_stop = i + 1;
        break;
      }
    }
    // Case 1: if all are in decreasing order, take no action just print as is
    // 4 3 2 1
    if (dec_stop == -1) {
      print(a);
      return;
    }
    int max_index = max_element(a.begin() + dec_stop, a.end()) - a.begin();
    reverse(a.begin() + dec_stop, a.begin() + max_index + 1);
  }
  print(a);
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
    // read n ints
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