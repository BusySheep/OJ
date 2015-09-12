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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            m[countChar(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        return result;
    }
};