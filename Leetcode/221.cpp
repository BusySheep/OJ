class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> maxLength;
        if (matrix.size() == 0) return 0;
        else if (matrix[0].size() == 0) return 0;
        maxLength.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        for (int i = 0; i < maxLength[0].size(); i++) {
            maxLength[0][i] = matrix[0][i] - '0';
            result = max(result, maxLength[0][i]);
        }
        for (int i = 0; i < maxLength.size(); i++) {
            maxLength[i][0] = matrix[i][0] - '0';
            result = max(result, maxLength[i][0]);
        }
        for (int i = 1; i < maxLength.size(); i++) {
            for (int j = 1; j < maxLength[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    maxLength[i][j] = 0;
                    continue;
                }
                maxLength[i][j] = min(maxLength[i - 1][j - 1], maxLength[i - 1][j]);
                maxLength[i][j] = min(maxLength[i][j], maxLength[i][j - 1]);
                maxLength[i][j]++;
                result = max(result, maxLength[i][j] * maxLength[i][j]);
            }
        }
        return result;
    }
};