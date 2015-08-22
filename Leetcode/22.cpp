#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void doGenerate(int remainLeft, int needRight, string& temp, vector<string>& result) {
        if (remainLeft == 0 && needRight == 0) {
            result.push_back(temp);
            return;
        }
        if (remainLeft > 0) {
            temp.push_back('(');
            doGenerate(remainLeft - 1, needRight + 1, temp, result);
            temp.pop_back();
        }
        if (needRight > 0) {
            temp.push_back(')');
            doGenerate(remainLeft, needRight - 1, temp, result);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        doGenerate(n, 0, temp, result);
        return result;
    }
};
int main() {
    int n;
    cin >> n;
    vector<string> result = Solution().generateParenthesis(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}