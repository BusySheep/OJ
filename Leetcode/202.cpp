class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }
        set<int> history;
        history.insert(n);
        while (n != 1) {
            int temp = n;
            n = 0;
            while (temp > 0) {
                int digit = temp % 10;
                temp /= 10;
                n += digit * digit;
            }
            if (history.count(n) == 1) {
                return false;
            }
            history.insert(n);
        }
        return true;
    }
};