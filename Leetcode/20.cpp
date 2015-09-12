class Solution {
public:
    bool isValid(string s) {
        map<char, char> match;
        map<char, char> reverseMatch;
        match['('] = ')';
        reverseMatch[')'] = '(';
        match['{'] = '}';
        reverseMatch['}'] = '{';
        match['['] = ']';
        reverseMatch[']'] = '[';
        stack<char> parentheses;
        for (int i = 0; i < s.length(); i++) {
            if (match.count(s[i]) != 0) {
                parentheses.push(s[i]);
            } else {
                if (parentheses.size() == 0 || parentheses.top() != reverseMatch[s[i]]) return false;
                else parentheses.pop();
            }
        }
        return parentheses.size() == 0;
    }
};