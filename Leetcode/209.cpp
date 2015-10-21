class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256);
        int remain = t.length();
        for (int i = 0; i < (int) t.length(); i++) {
            count[t[i]]++;
        }
        int bestI = -1;
        int bestJ = s.length();
        int i = 0;
        int j = 0;
        while (j < (int) s.length() || remain == 0) {
            if (remain > 0) {
                if (count[s[j]] > 0) remain--;
                count[s[j]]--;
                j++;
            } else {
                if (j - i < bestJ - bestI) {
                    bestI = i;
                    bestJ = j;
                }
                count[s[i]]++;
                if (count[s[i]] > 0) remain++;
                i++;
            }
        }
        if (bestI == -1) return "";
        else return s.substr(bestI, bestJ - bestI);
    }
};