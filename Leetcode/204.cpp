class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                if (INT_MAX / i > i) {
                    int temp = i * i;
                    while (temp < n) {
                        isPrime[temp] = false;
                        temp += i;
                    }
                }
            } else {
                isPrime[i] = false;
            }
        }
        return count;
    }
};