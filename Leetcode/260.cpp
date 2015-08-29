class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorResult ^= nums[i];
        }
        int firstOneBit = (xorResult ^ (xorResult - 1)) & xorResult;
        vector<int> part0;
        vector<int> part1;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & firstOneBit) == 0) {
                part0.push_back(nums[i]);
            } else {
                part1.push_back(nums[i]);
            }
        }
        vector<int> result;
        int temp = 0;
        for (int i = 0; i < part0.size(); i++) {
            temp ^= part0[i];
        }
        result.push_back(temp);
        temp = 0;
        for (int i = 0; i < part1.size(); i++) {
            temp ^= part1[i];
        }
        result.push_back(temp);
        return result;
    }
};