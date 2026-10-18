// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  // O(n) time, O(1) space
  // done by chatGPT, seems optimal solution
  int maxProfit(vector<int>& prices) {
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
  int maxProfit1(vector<int>& prices) {
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

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int low = prices[0], high = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (high > prices[i]) {
        maxProfit += (high - low);
        low = high = prices[i];
      } else {
        high = prices[i];
      }
    }
    maxProfit += (high - low);
    return maxProfit;
  }
};

struct TestCase {
  vector<int> prices;
  int maxProfit;
};

int main() {
  // set up tests first
  vector<TestCase> testCases = {
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
    int result = s.maxProfit(tc.prices);

    cout << "Test case #" << testCase << ": ";
    if (result != tc.maxProfit) {
      cout << "FAILED" << "\n";
      cout << "expected: " << tc.maxProfit << "\n";
      cout << "actual: " << result << "\n";
      continue;
    }

    // print like test case 1: passed
    cout << "Passed" << "\n";
  }
  cout << "\n";
  return 0;
}
