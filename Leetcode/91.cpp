class Solution {
public:
    int numDecodings(string s) {
        int dpPre2;
        int dpPre1;
        int dp;
        if (s.length() == 0) return 0;
        dpPre2 = dpPre1 = dp = s[0] != '0';
        if (s.length() > 1) {
            int temp = (s[0] - '0') * 10 + (s[1] - '0');
            dpPre1 = dp = (s[1] != '0' ? dpPre2 : 0) + (temp <= 26 && temp >= 10);
        }
        for (int i = 2; i < s.length(); i++) {
            int temp = (s[i - 1] - '0') * 10 + (s[i] - '0');
            dp = (s[i] != '0' ? dpPre1 : 0) + (temp <= 26 && temp >= 10 ? dpPre2 : 0);
            dpPre2 = dpPre1;
            dpPre1 = dp;
        }
        return dp;
    }
};