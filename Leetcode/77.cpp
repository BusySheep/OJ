#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    void doCombine(vector< vector<int> >& result, int n, int k, int index, vector<int>& temp) {
        if (k == 0) {
            result.push_back(temp);
            return;
        }
        if (n - index + 1 <= k) {
            for (int i = index; i <= n; i++) {
                temp.push_back(i);
            }
            result.push_back(temp);
            for (int i = index; i <= n; i++) {
                temp.pop_back();
            }
            return;
        }
        temp.push_back(index);
        doCombine(result, n, k - 1, index + 1, temp);
        temp.pop_back();
        doCombine(result, n, k, index + 1, temp);
    }
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > result;
        vector<int> temp;
        doCombine(result, n, k, 1, temp);
        return result;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector< vector<int> > result = Solution().combine(n, k);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}