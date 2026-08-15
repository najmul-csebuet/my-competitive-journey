#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
  if (s.size() <= 1) return s.size();
  int max_len = 0;
  unordered_map<char, int> seen;
  seen[s[0]] = 0;
  int left = 0, right = 1;

  for (; right < s.size(); right++) {
    if (seen.find(s[right]) != seen.end()) {
      // already seen
      max_len = max(max_len, right - left);
      left = max(left, seen[s[right]] + 1);
    }
    seen[s[right]] = right;
  }
  max_len = max(max_len, right - left);
  return max_len;
}

int solutionBetter(const string& s) {
  vector<int> lastSeen(256, -1);

  int left = 0;
  int maxLen = 0;

  for (int right = 0; right < s.size(); ++right) {
    unsigned char c = s[right];

    // If character was seen inside the current window,
    // move left past its previous occurrence.
    if (lastSeen[c] >= left) {
      left = lastSeen[c] + 1;
    }

    lastSeen[c] = right;

    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}

int main() {
  cout << (solution("") == 0) << endl;
  cout << (solution("a") == 1) << endl;
  cout << (solution("abcdabcd") == 4) << endl;
  cout << (solution("abcdamk") == 6) << endl;
  cout << (solution("abcabcabc") == 3) << endl;

  return 0;
}
