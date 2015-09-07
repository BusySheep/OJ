class Solution {
private:
    double positivePow(double x, int n) {
        if (n == 1) return x;
        double halfPow = myPow(x, n / 2);
        return halfPow * halfPow * ((n % 2) ? x : 1);
    }
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n < 0) return 1 / positivePow(x, -n);
        else return positivePow(x, n);
    }
};