class Solution {
    
    vector<vector<bool>> board;
    vector<vector<string>> result;
    set<int> rowsUsed;
    set<int> colsUsed;
    set<int> rowColSum;
    set<int> rowColDiff;
    int count;
    
private:
    bool check(int row, int col) {
        return rowsUsed.count(row) == 0
            && colsUsed.count(col) == 0
            && rowColSum.count(row + col) == 0
            && rowColDiff.count(row - col) == 0;
    }

    void doQueen(int index) {
        int n = board.size();
        if (index == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(index, i)) {
                board[index][i] = true;
                rowsUsed.insert(index);
                colsUsed.insert(i);
                rowColSum.insert(index + i);
                rowColDiff.insert(index - i);
                doQueen(index + 1);
                rowsUsed.erase(index);
                colsUsed.erase(i);
                rowColSum.erase(index + i);
                rowColDiff.erase(index - i);
                board[index][i] = false;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        board.assign(n, vector<bool>(n, false));
        count = 0;
        doQueen(0);
        return count;
    }
};