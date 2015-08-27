class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> result = digits;
        for (int i = result.size() - 1; i >= 0; i--) {
            int tempCarry = (result[i] + carry) / 10;
            result[i] = (result[i] + carry) % 10;
            carry = tempCarry;
        }
        if (carry == 1) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};