#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int solution(string s) {
  if (s.size() <= 1) return s.size();
  int max_len = 0;
  unordered_map<char, int> seen;
  seen[s[0]] = 0;
  int left = 0, right = 0;

  for (int i = 1; i < s.size(); i++) {
    if (seen.find(s[i]) == seen.end()) {
      seen[s[i]] = i;
    } else {
      // already seen
      max_len = max(max_len, right - left + 1);
      left = max(left, seen[s[i]] + 1);
    }
    right = i;
    seen[s[i]] = i;
  }
  max_len = max(max_len, right - left + 1);
  return max_len;
}

int main() {
  cout << (solution("") == 0) << endl;
  cout << (solution("a") == 1) << endl;
  cout << (solution("abcdabcd") == 4) << endl;
  cout << (solution("abcdamk") == 6) << endl;
  cout << (solution("abcabcabc") == 3) << endl;
  return 0;
}