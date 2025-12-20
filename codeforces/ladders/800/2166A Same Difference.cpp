#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// AC
void solve(string& st) {
  char last = st[st.size() - 1];
  int count = 0;
  for (char c : st) {
    if (c != last) {
      ++count;
    }
  }
  cout << count << endl;
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
    string st;
    cin >> st;
    // call solve function
    solve(st);
  }
  return 0;
}