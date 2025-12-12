#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC
void solve(vi &scores) {
  sort(scores.begin(), scores.end());
  int diff = scores[2] - scores[0];
  if (diff >= 10) {
    cout << "check again" << endl;
    return;
  }
  cout << "final " << scores[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif

  int testCases = 1;
  // cin >> testCases;

  while (testCases--) {
    // take input here
    vi scores(3);
    for (int i = 0; i < 3; i++) {
      cin >> scores[i];
    }
    // call solve function
    solve(scores);
  }
  return 0;
}