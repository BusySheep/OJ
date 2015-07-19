#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

struct Project {
    int p;
    int l;
    int d;
};

bool operator <(const Project& a, const Project& b) {
    return a.d < b.d;
}

int main() {
    int *f[51];
    int n;
    scanf("%d", &n);
    int maxD = 0;
    Project p[50];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &p[i].p, &p[i].l, &p[i].d);
        if (p[i].d > maxD) {
            maxD = p[i].d;
        }
    }
    sort(p, p + n);
    for (int i = 0; i <= n; i++) {
        f[i] = (int*)malloc((maxD + 1) * sizeof(int));
        memset(f[i], 0, (maxD + 1) * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= maxD; j++) {
            f[i + 1][j] = f[i][j];
            if (j >= p[i].l && j <= p[i].d) {
                f[i + 1][j] = max(f[i + 1][j], f[i][j - p[i].l] + p[i].p);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= maxD; i++) {
        if (f[n][i] > ans) {
            ans = f[n][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}


