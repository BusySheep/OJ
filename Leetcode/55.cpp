class Solution {
public:
    bool canJump(vector<int>& nums) {
        int oldMax = 1;
        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i] == 0) return false;
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
        }
        return true;
    }
};