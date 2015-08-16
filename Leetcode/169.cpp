class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> numCount;
        for (int i = 0; i < nums.size(); i++) {
            numCount[nums[i]]++;
        }
        for (auto it = numCount.begin(); it != numCount.end(); it++) {
            if (it->second > nums.size() / 2) {
                return it->first;
            }
        }
        return 0;
    }
};