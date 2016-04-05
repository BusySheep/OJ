#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

map<int,int> val;
map<int,int> cnt;
void init()
{
    int start=1; int cur=1; int a=1;
    while(start<=123456789)
    {
        val[cur]=start;
        cnt[start]=cur;
        a++;
        start+=a;
        cur++;
    }
}

int check(int n){
    int c = sqrt(2 * n + 0.25) - 0.5;
    if (n - c * (c + 1) / 2 != 0) {
        return 0;
    }
    else {
        return c;
    }
}

vector<int> cut(int n) {
    vector<int> result;
    int day1 = check(n);
    if (day1 != 0) {
        result.push_back(day1);
        return result;
    }
    for (int i = 1; i * i + i <= 2 * n; i++) {
        n -= i * (i + 1) / 2;
        int day2 = check(n);
        if (day2 != 0) {
            result.push_back(i);
            result.push_back(day2);
            return result;
        }
        n += i * (i + 1) / 2;
    }
    for (int i = 1; i * i + i <= 2 * n; i++) {
        n -= i * (i + 1) / 2;
        for (int j = 1; j * j + j <= 2 * n; j++) {
            n -= j * (j + 1) / 2;
            int days3 = check(n);
            if (days3 != 0) {
                result.push_back(i);
                result.push_back(j);
                result.push_back(days3);
                return result;
            }
            n += j * (j + 1) / 2;
        }
        n += i * (i + 1) / 2;
    }
    return result;
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> result = cut(n);
        for (int i = 0; i < result.size(); i++) {
            if (i) putchar(' ');
            printf("%d", result[i]);
        }
        putchar('\n');
    }
    return 0;
}

