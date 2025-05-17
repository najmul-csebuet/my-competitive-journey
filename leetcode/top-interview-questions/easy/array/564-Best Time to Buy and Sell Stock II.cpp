#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // O(n) time, O(1) space
  // done by chatGPT, seems optimal solution
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }

  // O(n) time, O(1) space
  // done by me, not so optimal solution
  int maxProfit1(vector<int> &prices) {

    int maxProfit = 0;
    int minPrice = prices[0], maxPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
      if (maxPrice <= prices[i]) {
        maxPrice = prices[i];
      } else {
        maxProfit += (maxPrice - minPrice);
        minPrice = prices[i];
        maxPrice = prices[i];
      }
    }
    maxProfit += (maxPrice - minPrice);
    return maxProfit;
  }
};

int main() {
  // set up tests first
  vector<pair<vector<int>, int>> testCases = {
      {{7, 1, 5, 3, 6, 4}, 7},
      {{1, 2, 3, 4, 5}, 4},
      {{7, 6, 4, 3, 1}, 0},
      {{0}, 0},
      {{1}, 0},
  };

  int testCase = 0;

  for (auto tc : testCases) {
    ++testCase;
    Solution s;
    int result = s.maxProfit(tc.first);

    cout << "Test case #" << testCase << ": ";
    if (result != tc.second) {
      cout << "FAILED" << "\n";
      cout << "expected: " << tc.second << "\n";
      cout << "actual: " << result << "\n";
      continue;
    }

    // print like test case 1: passed
    cout << "Passed" << "\n";
  }
  cout << "\n";
  return 0;
}
