class Solution {
public:
    int numDistinct(string s, string t) {
        vector<map<int, int>> ans;
        map<char, set<int>> charIndex;
        ans.resize(s.size());
        for (int i = 0; i < t.length(); i++) {
            charIndex[t[i]].insert(i);
        }
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndex.count(s[i]) > 0) {
                set<int>& indexSet = charIndex[s[i]];
                for (int index : indexSet) {
                    // s[i] == t[index]
                    int count = 0;
                    if (index == 0) count = 1;
                    else {
                        for (int j = 0; j < i; j++) {
                            if (s[j] == t[index - 1]) {
                                map<int, int>& indexCount = ans[j];
                                count += indexCount[index - 1];
                            }
                        }
                    }
                    ans[i][index] = count;
                    if (index == t.length() - 1) result += count;
                }
            }
        }
        return result;
    }
};