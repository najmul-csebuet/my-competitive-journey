#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n = 527000;
  long long ans = 0;
  for (long long i = 1; i < n; i += 2) {
    ans += (i * i);
  }
  cout << ans << endl;
  return 0;
}

// 1, 3,  5,  7,  9,  11
// 1, 9, 25, 49, 81, 121
// 1, 8, 16, 24, 32,  40