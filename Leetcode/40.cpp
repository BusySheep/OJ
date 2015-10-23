class Solution {
private:
    set<vector<int>> result;
    vector<int> current;
    void solve(int index, vector<int>& candidates, int target) {
        if (target == 0) {
            result.insert(current);
            return;
        }
        if (index == candidates.size()) return;
        if (candidates[index] > target) return;
        current.push_back(candidates[index]);
        solve(index + 1, candidates, target - candidates[index]);
        current.pop_back();
        solve(index + 1, candidates, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        current.clear();
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        vector<vector<int>> answer;
        for (auto it = result.begin(); it != result.end(); it++) {
            answer.push_back(*it);
        }
        return answer;
    }
};