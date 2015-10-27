class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string current;
        for (int i = 1; i <= path.length(); i++) {
            if (i < path.length() && path[i] != '/') {
                current += path[i];
            } else {
                if (current == "..") {
                    if (!s.empty()) s.pop_back();
                } else if (current != "" && current != ".") {
                    s.push_back(current);
                }
                current = "";
            }
        }
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            result += "/";
            result += s[i];
        }
        if (result == "") result += "/";
        return result;
    }
};