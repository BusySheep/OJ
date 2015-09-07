class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                int minStep = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                minStep = min(minStep, dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
                dp[i][j] = minStep;
            }
        }
        return dp[word1.length()][word2.length()];
    }
};