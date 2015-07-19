#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static bool cmp(string a, string b) {
        for (int i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] < b[i]) {
                return false;
            }
            else if (a[i] > b[i]) {
                return true;
            }
        }
        if (a.size() > b.size()) {
            for (int i = b.size(); i < a.size(); i++) {
                for (int j = 0; j < b.size(); j++) {
                    if (a[i] > a[j]) {
                        return true;
                    }
                    else if (a[i] < a[j]) {
                        return false;
                    }
                }
            }
        }
        else if (a.size() < b.size()){
            for (int i = a.size(); i < b.size(); i++) {
                for (int j = 0; j < a.size(); j++) {
                    if (b[i] > b[j]) {
                        return false;
                    }
                    else if (b[i] < b[j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    string largestNumber(vector<int> &num) {
        vector<string> numbers;
        for (int i = 0; i < num.size(); i++) {
            char temp[20];
            sprintf(temp, "%d", num[i]);
            numbers.push_back(temp);
        }
        sort(numbers.begin(), numbers.end(), cmp);
        if (numbers[0][0] == '0') {
            return "0";
        }
        string result;
        for (int i = 0; i < numbers.size(); i++) {
            result += numbers[i];
        }
        return result;
    }
};

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        num.push_back(x);
    }
    printf("%s\n", Solution().largestNumber(num).c_str());
    return 0;
}

