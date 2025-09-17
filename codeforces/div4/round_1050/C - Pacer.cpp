#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif

  int testCases;
  cin >> testCases;

  int n, m, a, b;
  while (testCases--) {
    int points = 0, lastTime = 0, lastSide = 0;
    cin >> n >> m;
    while (n--) {
      cin >> a >> b;

      int timePassed = a - lastTime;
      bool cross = b != lastSide;
      points += timePassed;
      if (cross) {
        --points;
      }

      lastTime = a;
      lastSide = b;
    }

    points += (m - lastTime);
    cout << points << endl;
  }

  return 0;
}

/*
Case 1:
-------
2 4

2 1
lastSide = 0
total time = 1
cross = true
points = 1

4 0
lastSide = 1
total time = 2
cross = true
points = 1

So total points = 1 + 1 = 2

Case 2:
-------
2 7

1 1
lastSide = 0
total time = 1
cross = true
points = 1

4 0
lastSide = 1
total time = 3
cross = true
points = 3

remaining time = 7 - 4 = 3
points = 1 + 3 + 3 = 7


4 9

1 0 => 0
2 0 => 0
6 1 => 3
9 0 => 3
*/