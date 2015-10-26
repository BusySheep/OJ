class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s.back() == ' ') s.pop_back();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') count++;
            else count = 0;
        }
        return count;
    }
};