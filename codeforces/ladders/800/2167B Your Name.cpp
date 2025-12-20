#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve(string first, string second) {
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  if (first == second) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
    string first, second;
    cin >> first >> second;
    // call solve function
    solve(first, second);
  }
  return 0;
}