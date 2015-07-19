#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10 + 26 + 26;

int colorNumber(char color) {
    if (color >= '0' && color <= '9') {
        return color - '0';
    }
    else if (color >= 'a' && color <= 'z') {
        return color - 'a' + 10;
    }
    else {
        return color - 'A' + 10 + 26;
    }
}

int main() {
    char beads[1001];
    int color1[N];
    int color2[N];
    memset(color1, 0, N * sizeof(int));
    memset(color2, 0, N * sizeof(int));
    gets(beads);
    for (int i = 0; beads[i]; i++) {
        color1[colorNumber(beads[i])]++;
    }
    gets(beads);
    for (int i = 0; beads[i]; i++) {
        color2[colorNumber(beads[i])]++;
    }
    int count1 = 0;
    int count2 = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (color1[i] < color2[i]) {
            flag = true;
            count2 += color2[i] - color1[i];
        }
        else {
            count1 += color1[i] - color2[i];
        }
    }
    if (!flag) {
        printf("Yes %d\n", count1);
    }
    else {
        printf("No %d\n", count2);
    }
    return 0;
}
