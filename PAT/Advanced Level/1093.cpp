#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    long ans = 0;
    vector<int> countP(str.length(), 0);
    vector<int> countT(str.length(), 0);
    if (str.length() == 0) goto OUT;
    countP[0] = str[0] == 'P';
    countT[countT.size() - 1] = str[str.length() - 1] == 'T';
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == 'P') countP[i] = countP[i - 1] + 1;
        else countP[i] = countP[i - 1];
    }
    for (int i = str.length() - 2; i >= 0; i--) {
        if (str[i] == 'T') countT[i] = countT[i + 1] + 1;
        else countT[i] = countT[i + 1];
        if (str[i] == 'A') {
            ans += countP[i] * countT[i];
            ans %= 1000000007;
        }
    }
    OUT:
    printf("%ld\n", ans);
    return 0;
}