class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) return nums.size();
        int j = 1;
        int count = 1;
        int old = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == old) {
                count++;
                if (count <= 2) {
                    nums[j++] = nums[i];
                }
            } else {
                old = nums[i];
                count = 1;
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};