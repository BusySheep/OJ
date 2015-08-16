#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
private:
    bool check(int m, int n, int i, int j, vector< vector<bool> >& visited) {
        return i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == false;
    }

public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }
        int m = matrix.size();
        int n = matrix[0].size();
        static int dirI[4] = {0, 1, 0, -1};
        static int dirJ[4] = {1, 0, -1, 0};
        vector<int> result;
        vector< vector<bool> > visited(m, vector<bool>(n, false));
        int dirIndex = 0;
        int i = 0;
        int j = 0;
        result.push_back(matrix[i][j]);
        visited[i][j] = true;
        int total = m * n;
        while (result.size() < total) {
            int nextI = i + dirI[dirIndex];
            int nextJ = j + dirJ[dirIndex];
            if (!check(m, n, nextI, nextJ, visited)) {
                dirIndex = (dirIndex + 1) % 4;
                nextI = i + dirI[dirIndex];
                nextJ = j + dirJ[dirIndex];
            }
            i = nextI;
            j = nextJ;
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
        return result;
    }
};
int main() {
    int n;
    int m;
    cin >> m >> n;
    vector< vector<int> > matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> result = Solution().spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    return 0;
}