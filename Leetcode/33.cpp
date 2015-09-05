class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] == target) return l;
            if (nums[r - 1] == target) return r - 1;
            if (nums[mid] >= nums[l]) {
                // the left area is normally sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                // the right area is normally sorted
                if (target <= nums[r - 1] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        return -1;
    }
};