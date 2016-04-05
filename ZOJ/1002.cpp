#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int mark[4][4];
int ans = 0;
int cnt = 0;
char city[4][5];
int n;

bool check(int i, int j) {
    if (i < 0 || j < 0) {
        return false;
    }
    if (i >= n || j >= n) {
        return false;
    }
    if (city[i][j] == 'X') {
        return false;
    }
    return true;
}

void dfs(int index) {
    static int moveX[4] = {0, 0, -1, 1};
    static int moveY[4] = {-1, 1, 0, 0};
    int j = index % n;
    int i = index / n;
    if (index == n * n) {
        if (cnt > ans) {
            ans = cnt;
        }
        return;
    }
    
    //unuse
    dfs(index + 1);
    if (city[i][j] == 'X' || mark[i][j] > 0) {
        return;
    }
    
    //use
    mark[i][j]++;
    for (int dir = 0; dir < 4; dir++) {
        for (int ri = 1; ri <= n; ri++) {
            int newI = i + moveY[dir] * ri;
            int newJ = j + moveX[dir] * ri;
            if (check(newI, newJ)) {
                mark[newI][newJ]++;
            }
            else {
                break;
            }
        }
    }
    cnt++;
    dfs(index + 1);
    cnt--;
    mark[i][j]--;
    for (int dir = 0; dir < 4; dir++) {
        for (int ri = 1; ri <= n; ri++) {
            int newI = i + moveY[dir] * ri;
            int newJ = j + moveX[dir] * ri;
            if (check(newI, newJ)) {
                mark[newI][newJ]--;
            }
            else {
                break;
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    getchar();
    while (n) {
        for (int i = 0; i < n; i++) {
            gets(city[i]);
        }
        
        memset(mark, 0, 4 * 4 * sizeof(int));
        cnt = 0;
        ans = 0;
        dfs(0);
        printf("%d\n", ans);
        scanf("%d", &n);
        getchar();
    }
}
