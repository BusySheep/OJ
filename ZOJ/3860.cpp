#include <cstdio>
#include <map>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        map<int, int> count;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            count[x]++;
        }
        auto it = count.begin();
        if (it->second == 1) {
            printf("%d\n", it->first);
        }
        else {
            it++;
            printf("%d\n", it->first);
        }
    }
    return 0;
}

