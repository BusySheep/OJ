class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        queue<int> q;
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i]) == 1) {
                return true;
            } else {
                s.insert(nums[i]);
                q.push(nums[i]);
                if (q.size() > k) {
                    s.erase(q.front());
                    q.pop();
                }
            }
        }
        return false;
    }
};