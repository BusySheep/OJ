class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int temp = dungeon[m - 1][n - 1];
        if (temp < 0) dp[m - 1][n - 1] = -temp + 1;
        else dp[m - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int temp1 = max(1, dp[i + 1][j] - dungeon[i][j]);
                int temp2 = max(1, dp[i][j + 1] - dungeon[i][j]);
                dp[i][j] = min(temp1, temp2);
            }
        }
        return dp[0][0];
    }
};