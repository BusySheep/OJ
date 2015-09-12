class Solution {
    vector<string> result;
    string current;
private:
    vector<string> findCombinations(const string& digits, int index) {
        const static vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (index >= digits.length()) {
            result.push_back(current);
            return result;
        }
        string currentMapping = mapping[digits[index] - '2'];
        for (int i = 0; i < currentMapping.length(); i++) {
            current.push_back(currentMapping[i]);
            findCombinations(digits, index + 1);
            current.pop_back();
        }
        return result;
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>();
        for (int i = 0; i < digits.length(); i++) {
            if (digits[i] < '2' || digits[i] > '9') return vector<string>();
        }
        return findCombinations(digits, 0);
    }
};