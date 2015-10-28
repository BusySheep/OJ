class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return true;
            if (nums[l] == target) return true;
            if (nums[r - 1] == target) return true;
            if (nums[mid] > nums[l] || nums[mid] > nums[r - 1]) {
                // the left area is normally sorted
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[l] || nums[mid] < nums[r - 1]) {
                // the right area is normally sorted
                if (target <= nums[r - 1] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                l++;
            }
        }
        return false;
    }
};