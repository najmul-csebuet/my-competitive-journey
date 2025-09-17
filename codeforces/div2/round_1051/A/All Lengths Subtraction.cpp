#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &A) {
  // find max element index
  int maxIndex = -1;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == A.size()) {
      maxIndex = i;
      break;
    }
  }

  int i = maxIndex, j = maxIndex, find = A.size() - 1;
  // now try to expand this range
  bool flag;
  while (find > 1 && i >= 0 && j < A.size()) {
    flag = false;
    if (i > 0 && A[i - 1] == find) {
      i--;
      flag = true;
    } else if (j < A.size() - 1 && A[j + 1] == find) {
      j++;
      flag = true;
    }
    find--;
    if (!flag) break;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    solve(A);
  }
  return 0;
}