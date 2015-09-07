class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0 || strs[0].size() == 0) return result;
        int index = 0;
        while (true) {
            bool breakFlag = false;
            for (int i = 0; i < strs.size(); i++) {
                if (index >= strs[i].size() || strs[i][index] != strs[0][index]) goto OUT;
            }
            result.push_back(strs[0][index]);
            index++;
        }
        OUT:
        return result;
    }
};