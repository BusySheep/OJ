#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        vector<int> max = num;
        int result = max[0];
        for (int i = 1; i < max.size(); i++) {
            int m = 0;
            for (int j = 0; j < i - 1; j++) {
                if (max[j] > m) {
                    m = max[j];
                }
            }
            max[i] += m;
            if (max[i] > result) {
                result = max[i];
            }
        }
        return result;
    }
};

int main(void) {
    vector<int> num;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        num.push_back(x);
    }
    printf("%d\n", Solution().rob(num));
    return 0;
}
