class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minSum = triangle;
        for (int i = minSum.size() - 2; i >= 0; i--)
            for (int j = 0; j < minSum[i].size(); j++)
                minSum[i][j] = min(minSum[i][j] + minSum[i + 1][j], minSum[i][j] + minSum[i + 1][j + 1]);
        return minSum[0][0];
    }
};