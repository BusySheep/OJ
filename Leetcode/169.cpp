class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int saveNumber;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                saveNumber = nums[i];
                count = 1;
            } else {
                if (nums[i] == saveNumber) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return saveNumber;
    }
};