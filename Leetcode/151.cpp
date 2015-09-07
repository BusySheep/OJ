class Solution {
public:
    void reverseWords(string &s) {
        // remove surplus space
        int i;
        for (i = 0; i < s.length() && s[i] == ' '; i++) ;
        int countSpace = 0;
        int newLength = 0;
        for (; i < s.length(); i++) {
            if (s[i] == ' ') countSpace++;
            else countSpace = 0;
            if (countSpace < 2) s[newLength++] = s[i];
        }
        s.resize(newLength);
        if (s[newLength - 1] == ' ') s.pop_back(); // remove the trailing space
        
        // reverse words
        int wordBegin = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + wordBegin, s.begin() + i);
                wordBegin = i + 1;
            }
        }
        reverse(s.begin() + wordBegin, s.end()); // reverse the last word
        reverse(s.begin(), s.end()); //reverse the whole string to get result;
    }
};