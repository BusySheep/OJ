class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            int temp = n % 26;
            n /= 26;
            if (temp != 0) {
                result += temp - 1 + 'A';
            } else {
                result += 'Z';
                n--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};