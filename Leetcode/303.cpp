class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum = nums;
        for (int i = 1; i < nums.size(); i++) {
            sum[i] += sum[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return sum[j] - (i > 0 ? sum[i - 1] : 0);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);