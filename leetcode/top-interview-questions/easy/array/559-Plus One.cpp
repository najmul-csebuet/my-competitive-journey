#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (int i = sz(digits) - 1; i >= 0; --i) {
      int s = digits[i] + carry;
      digits[i] = s % 10;
      carry = s / 10;
    }
    if (carry) digits.emplace(digits.begin(), carry);
    return digits;
  }

  vector<int> plusOneReverse(vector<int>& digits) {
    reverse(all(digits));
    int carry = 1;
    for (int i = 0; i < sz(digits); ++i) {
      int s = digits[i] + carry;
      digits[i] = s % 10;
      carry = s / 10;
    }
    if (carry) digits.pb(carry);
    reverse(all(digits));

    return digits;
  }
};

struct TestCase {
  vi digits, ans;
};

int main() {
  vector<TestCase> testCases = {
      {{1, 2, 3}, {1, 2, 4}},
      {{9}, {1, 0}},
      {{9, 9}, {1, 0, 0}},
  };

  Solution solution;

  for (auto& tc : testCases) {
    vi result = solution.plusOne(tc.digits);
    // assert(tc.ans == result);
    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  // for (auto& tc : testCases) {
  //   vi result = solution.plusOneReverse(tc.digits);
  //   // assert(tc.ans == result);
  //   if (tc.ans == result) {
  //     cout << "Success\n";
  //   } else {
  //     cout << "Failed\n";
  //   }
  // }

  return 0;
}