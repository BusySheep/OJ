class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int mid = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            long square = (long) mid * mid;
            if (square == x) return mid;
            else if (square > x) r = mid - 1;
            else l = mid + 1;
        }
        if (mid * mid > x) return mid - 1;
        else return mid;
    }
};