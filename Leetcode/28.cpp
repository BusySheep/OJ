class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < (int) haystack.length() - (int) needle.length() + 1; i++) {
            int j;
            for (j = 0; j < needle.length(); j++) {
                if (needle[j] != haystack[i + j]) break;
            }
            if (j >= needle.length()) {
                return i;
            }
        }
        return -1;
    }
};