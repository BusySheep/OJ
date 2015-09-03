class Solution {
private:
    bool singleDirectMap(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int mapping[128];
        memset(mapping, -1, sizeof(mapping));
        for (int i = 0; i < s.length(); i++) {
            if (mapping[s[i]] == -1) {
                mapping[s[i]] = t[i];
            } else if (mapping[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return singleDirectMap(s, t) && singleDirectMap(t, s);
    }
};