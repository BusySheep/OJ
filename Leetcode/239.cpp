class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<pair<int, int>> q;
        int i;
        for (i = 0; i < k - 1; i++) {
            while (!q.empty() && q.back().first < nums[i]) q.pop_back();
            q.push_back(make_pair(nums[i], i));
        }
        for (; i < nums.size(); i++) {
            if (!q.empty() && i - q.front().second == k) q.pop_front();
            while (!q.empty() && q.back().first < nums[i]) q.pop_back();
            q.push_back(make_pair(nums[i], i));
            result.push_back(q.front().first);
        }
        return result;
    }
};