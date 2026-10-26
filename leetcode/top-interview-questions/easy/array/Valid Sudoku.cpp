// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using vi = vector<int>;
using sc = set<char>;
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
  bool isValidSudoku_AC(vector<vector<char>>& board) {
    // first check all rows
    rep(row, 0, sz(board)) {
      sc nums;
      rep0(sz(board[row])) {
        char ch = board[row][i];
        if (ch == '.') continue;
        if (!nums.insert(ch).second) {
          // failed to insert as it is duplicate
          // invalid sudoku
          return false;
        }
      }
    }

    // now check all columns
    rep(col, 0, sz(board[0])) {
      sc nums;
      rep0(sz(board)) {
        char ch = board[i][col];
        if (ch == '.') continue;
        if (!nums.insert(ch).second) {
          // failed to insert as it is duplicate
          // invalid sudoku
          return false;
        }
      }
    }

    // now check all 3 x 3 sub-boxes of the grid
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        sc nums;
        // sub-grid
        rep(k, 0, 3) {    // rows
          rep(l, 0, 3) {  // cols
            char ch = board[i + k][j + l];
            if (ch == '.') continue;
            if (!nums.insert(ch).second) {
              // failed to insert as it is duplicate
              // invalid sudoku
              return false;
            }
          }
        }
      }
    }

    // valid sudoku
    return true;
  }

  bool isValidSudoku_StringTags(vector<vector<char>>& board) {
    unordered_set<string> seen;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char curr = board[i][j];
        if (curr == '.') continue;

        string row_tag = string(1, curr) + "@row" + to_string(i);
        string col_tag = string(1, curr) + "@col" + to_string(j);
        string box_tag = string(1, curr) + "@box" + to_string(i / 3) + "_" +
                         to_string(j / 3);

        if (seen.count(row_tag) || seen.count(col_tag) || seen.count(box_tag)) {
          return false;
        }

        seen.insert(row_tag);
        seen.insert(col_tag);
        seen.insert(box_tag);
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>>& board) {
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
        if (board[i][j] != '.') {
          int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
          if (used1[i][num] || used2[j][num] || used3[k][num]) return false;
          used1[i][num] = used2[j][num] = used3[k][num] = 1;
        }

    return true;
  }
};

struct TestCase {
  vector<vector<char>> board;
  bool ans;
};

int main() {
  vector<vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  vector<vector<char>> board2 = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  vector<TestCase> testCases = {{board1, true}, {board2, false}};

  Solution solution;

  for (auto& tc : testCases) {
    bool result = solution.isValidSudoku(tc.board);

    if (tc.ans == result) {
      cout << "Success\n";
    } else {
      cout << "Failed\n";
    }
  }

  return 0;
}