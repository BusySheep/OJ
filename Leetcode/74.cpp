#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        if (matrix[matrix.size() - 1][0] <= target) return binary_search(matrix[matrix.size() - 1].begin(), matrix[matrix.size() - 1].end(), target);
        int l = 0;
        int r = matrix.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid < matrix.size() - 1 && matrix[mid][0] <= target && matrix[mid + 1][0] > target) {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            } else if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int> > matrix;
    for (int i = -8; i <= 94; i++) {
        matrix.push_back(vector<int>{i});
    }
    cout << Solution().searchMatrix(matrix, 57) << endl;
    return 0;
}