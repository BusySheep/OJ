class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = !obstacleGrid[0][0];
        for (int i = 1; i < n; i++) dp[i] = obstacleGrid[0][i] ? 0 : dp[i - 1];
        for (int i = 1; i < m; i++) {
            dp[0] = obstacleGrid[i][0] ? 0 : dp[0];
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) dp[j] = 0;
                else dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};