class Solution {
private:
    void compress(vector<pair<int, int>>& previous) {
        int i;
        for (i = previous.size() - 2; i >= 0; i--) {
            if (previous[i].second == previous[i + 1].first) previous[i].second = previous[i + 1].second;
            else break;
        }
        previous.resize(i + 2);
    }
public:
    int longestValidParentheses(string s) {
        vector<pair<int, int>> previous;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && i > 0) {
                if (s[i - 1] == '(') {
                    int begin = i - 1;
                    int end = i + 1;
                    previous.push_back(make_pair(begin, end));
                    compress(previous);
                } else if (!previous.empty()) {
                    auto pre = *previous.rbegin();
                    if (i == pre.second && pre.first > 0 && s[pre.first - 1] == '(') {
                        int begin = pre.first - 1;
                        int end = i + 1;
                        previous.pop_back();
                        previous.push_back(make_pair(begin, end));
                        compress(previous);
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < previous.size(); i++) {
            result = max(result, previous[i].second - previous[i].first);
        }
        return result;
    }
};