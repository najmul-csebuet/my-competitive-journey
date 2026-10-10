#include <bits/stdc++.h>
using namespace std;

// Brute force, O(n^2)
void solution1(string input, int ans) {
  int bestSoFarAns = 1;  // 1 char long substring is alaways unique
  for (int i = 0; i < input.length(); ++i) {
    for (int j = i + 1; j < input.length(); ++j) {
      vector<int> map(26, 0);
      int sum = 0;
      for (int k = i; k <= j; ++k) {
        if (map[input[k] - 'a']) {
          // duplicate found, break;
          break;
        }
        ++sum;
        map[input[k] - 'a'] = 1;
      }
      bestSoFarAns = max(bestSoFarAns, sum);
    }
  }
  cout << "Test: " << (new string[]{"failed", "passed"})[(bestSoFarAns == ans)]
       << endl;
}

// buggy
// Still O(n^2)
// for input: abcdefghabcdefgh
void solution2(string input, int ans) {
  int bestSoFarAns = 0;

  int localSum = 0;
  vector<int> map(26, 0);
  vector<int> lastIndex(26, -1);

  for (int i = 0; i < input.length(); ++i) {
    if (map[input[i] - 'a'] == 0) {
      // this char is not seen yet
      ++localSum;
      map[input[i] - 'a'] = 1;
      lastIndex[input[i] - 'a'] = i;
      continue;
    }

    // oh this char is already seen before,
    // next candidate should start from this char
    bestSoFarAns = max(bestSoFarAns, localSum);
    localSum = 0;
    for (int x = 0; x < map.size(); ++x) {
      map[x] = 0;
    }
    i = lastIndex[input[i] - 'a'];
  }
  bestSoFarAns = max(bestSoFarAns, localSum);
  cout << "Test: " << (new string[]{"failed", "passed"})[(bestSoFarAns == ans)]
       << endl;
}

// abcabcbb --> 3
int solution(const string& input, int ans) {
  int best = 0;
  vector<int> lastIndex(128, -1);
  for (int left = 0, right = 0; right < input.length(); ++right) {
    char c = input[right];
    if (lastIndex[c] == -1) {
      // new char, save this index
      lastIndex[c] = right;
      best = max(best, right - left + 1);
    } else {
      // duplicate found
      left = lastIndex[c] + 1;
      lastIndex[c] = right;
    }
  }

  if (best == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed\n";
  }
  return best;
}

struct TestCase {
  string input;
  int ans;
};

int new_solution(const string& input) {
  int best = 0;
  vector<int> lastIndex(127, -1);

  for (int l = 0, r = 0; r < input.length(); ++r) {
    if (lastIndex[input[r]] == -1 || (lastIndex[input[r]] < l)) {
      // not seen yet
      // save postion
      lastIndex[input[r]] = r;
      best = max(best, r - l + 1);
      continue;
    }

    // already seen this char
    // update left pointer l
    l = lastIndex[input[r]] + 1;
    lastIndex[input[r]] = r;
  }

  return best;
}

int main() {
  vector<TestCase> testCases = {{"abcabcbb", 3}, {"abcabcdbb", 4}, {"bbbb", 1},
                                {"abcdefgh", 8}, {"dvdf", 3},      {"abba", 2},
                                {"tmmzuxt", 5}};

  for (const auto& tc : testCases) {
    // solution(tc.input, tc.ans);
    int ans = new_solution(tc.input);
    if (ans == tc.ans) {
      cout << "Passed" << endl;
    } else {
      cout << "Failed: " << tc.input << ": " << ans << " -- " << tc.ans << endl;
    }
  }

  return 0;
}
