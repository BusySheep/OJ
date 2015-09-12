class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<bool> hash(10, false);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                if (hash[board[i][j] - '0']) return false;
                hash[board[i][j] - '0'] = true;
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            vector<bool> hash(10, false);
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == '.') continue;
                if (hash[board[i][j] - '0']) return false;
                hash[board[i][j] - '0'] = true;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> hash(10, false);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char c = board[i + k][j + l];
                        if (c == '.') continue;
                        if (hash[c - '0']) return false;
                        hash[c - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};