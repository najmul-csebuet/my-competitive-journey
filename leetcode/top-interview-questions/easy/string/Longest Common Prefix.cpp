// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/array/887/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using mii = map<int, int>;
using pii = pair<int, int>;
using umii = unordered_map<int, int>;

// Useful Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep0(n) for (int i = 0; i < (n); ++i)
// Note: If you nest these, use different variable names or stick to the
// 3-parameter version.
#define repr(i, a, b) for (int i = (a) - 1; i >= (b); --i)

class Solution {
 public:
  string longestCommonPrefix(vs& strs) {
    const string& first = strs[0];

    rep(i, 0, sz(first)) {
      rep(j, 1, sz(strs)) {
        if (i == sz(strs[j])) {
          return strs[j];
        }

        if (first[i] != strs[j][i]) {
          return first.substr(0, i);
        }
      }
    }
    return first;
  }
};

/*
Alternative approaches (for interview discussion)
--------------------------------------------------
1. Sort, then compare first and last. After sorting, the common prefix of the
whole set equals the common prefix of the lexicographically smallest and largest
strings. This is O(S log n) but very short to write.

2. Trie. Overkill for a single
query, but it’s the right structure if you need many prefix queries.

3. Divide and
conquer / binary search on length. Same asymptotics, and good to know, but
vertical scanning is the answer interviewers expect.
*/

class SolutionSort {
 public:
  string longestCommonPrefix(vs& strs) {
    if (strs.empty()) return "";

    sort(all(strs));

    const string& first = strs.front();
    const string& last = strs.back();

    int i = 0;
    int limit = min(sz(first), sz(last));
    while (i < limit && first[i] == last[i]) ++i;

    return first.substr(0, i);
  }
};

class TrieNode {
 public:
  TrieNode* children[26];
  bool isEnd;
  int linkCount;  // To count the number of children

  TrieNode() : isEnd(false), linkCount(0) {
    for (int i = 0; i < 26; ++i) {
      children[i] = nullptr;
    }
  }

  void put(char ch, TrieNode* node) {
    if (children[ch - 'a'] == nullptr) {
      children[ch - 'a'] = node;
      linkCount++;
    }
  }

  bool contains(char ch) { return children[ch - 'a'] != nullptr; }

  int getLinks() const { return linkCount; }
};

class Trie {
 public:
  TrieNode* root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->contains(c)) {
        node->put(c, new TrieNode());
      }
      node = node->children[c - 'a'];
    }
    node->isEnd = true;
  }

  string searchLongestPrefix(string word) {
    TrieNode* node = root;
    string prefix;
    for (char c : word) {
      if (node->contains(c) && node->getLinks() == 1 && !node->isEnd) {
        prefix += c;
        node = node->children[c - 'a'];
      } else {
        break;
      }
    }
    return prefix;
  }
};

class SolutionTrie {
 public:
  string longestCommonPrefix(string q, vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    Trie trie;
    for (int i = 1; i < strs.size(); i++) {
      trie.insert(strs[i]);
    }
    return trie.searchLongestPrefix(q);
  }
};

struct TestCase {
  string name;
  vs input;
  string ans;
};

vector<TestCase> getTests() {
  return {
      {"leetcode example 1", {"flower", "flow", "flight"}, "fl"},
      {"leetcode example 2", {"dog", "racecar", "car"}, ""},
      {"mismatch at last char", {"abb", "abc"}, "ab"},
      {"single string", {"a"}, "a"},
      {"single empty string", {""}, ""},
      {"empty string in list", {"", "b"}, ""},
      {"later string is prefix of first", {"ab", "a"}, "a"},
      {"first string is prefix of later", {"a", "ab"}, "a"},
      {"all identical", {"same", "same", "same"}, "same"},
      {"shortest string is last", {"abc", "abd", "abx", "ab"}, "ab"},
  };
}

string show(const vs& v) {
  string s = "[";
  rep(i, 0, sz(v)) {
    if (i) s += ", ";
    s += '"' + v[i] + '"';
  }
  return s + "]";
}

int main() {
  auto testCases = getTests();
  Solution solution;
  int passed = 0;

  for (auto& tc : testCases) {
    vs input = tc.input;  // copy in case the solution mutates its argument
    string result = solution.longestCommonPrefix(input);

    if (result == tc.ans) {
      ++passed;
    } else {
      cout << "FAIL: " << tc.name << "\n"
           << "  input:    " << show(tc.input) << "\n"
           << "  expected: \"" << tc.ans << "\"\n"
           << "  actual:   \"" << result << "\"\n";
    }
  }

  cout << passed << "/" << sz(testCases) << " passed\n";
  return passed == sz(testCases) ? 0 : 1;
}