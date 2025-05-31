#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // do xor of all elements
    int xor_val = 0;
    for (int num : nums) {
      xor_val ^= num;
    }
    // return the xor_val
    return xor_val;
  }
};

int main() { return 0; }