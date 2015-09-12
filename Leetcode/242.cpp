class Solution {
private:
    vector<int> countChar(string str) {
        vector<int> count(26, 0);
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a']++;
        }
        return count;
    }
public:
    bool isAnagram(string s, string t) {
        return countChar(s) == countChar(t);
    }
};