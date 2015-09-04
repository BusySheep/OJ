class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int oldMax = 1;
        for (int i = 0; i < nums.size() - 1; ) {
            int bestJumpTo = oldMax - i;
            for (int j = oldMax - i + 1; j <= nums[i]; j++) {
                if (i + j >= nums.size() - 1) {
                    bestJumpTo = nums.size() - 1 - i;
                    break;
                }
                if (nums[i + j] + i + j > nums[i + bestJumpTo] + i + bestJumpTo) {
                    bestJumpTo = j;
                }
            }
            oldMax = i + nums[i];
            i += bestJumpTo;
            count++;
        }
        return count;
    }
};