class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l < r - 1) {
            if (nums[l] < nums[r - 1]) return nums[l];
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid - 1]) return nums[mid];
            if (nums[mid] > nums[l] || nums[mid] > nums[r - 1]) {
                // the left part is normal sorted
                l = mid + 1;
            } else if (nums[mid] < nums[l] || nums[mid] < nums[r - 1]) {
                r = mid;
            } else {
                l++;
            }
        }
        return nums[l];
    }
};