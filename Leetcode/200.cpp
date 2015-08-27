class Solution {
private:
    const int dirI[4] = {-1, 1, 0, 0};
    const int dirJ[4] = {0, 0, -1, 1};
    bool check(int i, int j, const vector<vector<char>>& grid) {
        if (grid.size() == 0) return false;
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (int index = 0; index < 4; index++) {
            int nextI = i + dirI[index];
            int nextJ = j + dirJ[index];
            if (check(nextI, nextJ, grid) && !visited[nextI][nextJ] && grid[nextI][nextJ] == '1') {
                dfs(nextI, nextJ, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};