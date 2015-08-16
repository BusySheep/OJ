#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
private:
    bool check(int n, int i, int j, vector< vector<bool> >& visited) {
        return i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false;
    }
public:
    vector< vector<int> > generateMatrix(int n) {
        if (n <= 0) {
            return vector< vector<int> >();
        }
        static int dirI[4] = {0, 1, 0, -1};
        static int dirJ[4] = {1, 0, -1, 0};
        vector< vector<int> > result(n, vector<int>(n, 0));
        vector< vector<bool> > visited(n, vector<bool>(n, false));
        int number = 0;
        int dirIndex = 0;
        int i = 0;
        int j = 0;
        result[i][j] = ++number;
        visited[i][j] = true;
        int nSquare = n * n;
        while (number < nSquare) {
            int nextI = i + dirI[dirIndex];
            int nextJ = j + dirJ[dirIndex];
            if (!check(n, nextI, nextJ, visited)) {
                dirIndex = (dirIndex + 1) % 4;
                nextI = i + dirI[dirIndex];
                nextJ = j + dirJ[dirIndex];
            }
            i = nextI;
            j = nextJ;
            result[i][j] = ++number;
            visited[i][j] = true;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector< vector<int> > result = Solution().generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    return 0;
}