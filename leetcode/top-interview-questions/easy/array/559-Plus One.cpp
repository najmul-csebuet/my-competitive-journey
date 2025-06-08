#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      digits[i] += carry;
      carry = digits[i] / 10;
      digits[i] %= 10;
    }
    if (carry) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};

void test1() {
  vector<int> digits = {1, 2, 3};
  vector<int> ans = {1, 2, 4};
  assert(Solution().plusOne(digits) == ans);
}

void test2() {
  vector<int> digits = {9};
  vector<int> ans = {1, 0};
  assert(Solution().plusOne(digits) == ans);
}

void test3() {
  vector<int> digits = {9, 9};
  vector<int> ans = {1, 0, 0};
  assert(Solution().plusOne(digits) == ans);
}

int main() {
  test1();
  test2();
  test3();
  cout << "All tests passed!" << endl;
  return 0;
}