#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int>& candidates, int begin, int target, vector<int>& current, vector<vector<int>>& result) {
        if (candidates[begin] > target) return;
        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
            current.push_back(candidates[i]);
            if (candidates[i] == target) {
                result.push_back(current);
            } else {
                solve(candidates, i, target - candidates[i], current, result);
            }
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        unique(candidates.begin(), candidates.end());
        solve(candidates, 0, target, current, result);
        return result;
    }
};

int main() {
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    auto result = Solution().combinationSum(candidates, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    return 0;
}