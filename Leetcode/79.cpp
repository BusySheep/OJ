#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool check(int x, int y, vector< vector<char> >& board) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    bool doExist(int x, int y, vector< vector<char> >& board, int index, string& word) {
        const static int dirX[4] = {-1, 1, 0, 0};
        const static int dirY[4] = {0, 0, -1, 1};
        if (index == word.length()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = x + dirX[i];
            int nextY = y + dirY[i];
            if (check(nextX, nextY, board) == false) {
                continue;
            }
            if (visited[nextX][nextY]) {
                continue;
            }
            visited[nextX][nextY] = true;
            if (doExist(nextX, nextY, board, index + 1, word)) {
                return true;
            }
            visited[nextX][nextY] = false;
        }
        return false;
    }
    vector< vector<bool> > visited;
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (word == "") {
            return true;
        } else if (board.size() == 0) {
            return false;
        } else if (board.size() * board[0].size() < word.size()) {
            return false;
        }
        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (doExist(i, j, board, 0, word)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
int main() {
    vector< vector<char> > board;
    board.push_back(vector<char>(1, 'a'));
    cout << Solution().exist(board, "ab") << endl;
    return 0;
}