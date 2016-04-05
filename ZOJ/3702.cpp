#include <cstdio>
#include <algorithm>
using namespace std;

int coe[21];
int constant[21];

void init() {
    coe[0] = coe[1] = coe[2] = 1;
    constant[0] = 1;
    constant[1] = 0;
    constant[2] = 1;
    for (int i = 3; i < 21; i++) {
        coe[i] = coe[i - 1] + coe[i - 2];
        constant[i] = constant[i - 1] + constant[i - 2];
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int i;
        int gi;
        int j;
        scanf("%d%d%d", &i, &gi, &j);
        int t = 0;
        if ((gi - constant[i]) % coe[i] == 0) {
            t = (gi - constant[i]) / coe[i];
        }
        if (t <= 0) {
            printf("-1\n");
        }
        else {
            long g[21];
            g[0] = 1;
            g[1] = t;
            for (int index = 2; index <= j; index++) {
                g[index] = g[index - 1] + g[index - 2];
            }
            printf("%ld\n", g[j]);
        }
    }
    return 0;
}
