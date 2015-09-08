#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    char sellBead[1001];
    char needBead[1001];
    gets(sellBead);
    gets(needBead);
    vector<int> have(128, 0);
    for (int i = 0; sellBead[i]; i++) {
        have[sellBead[i]]++;
    }
    for (int i = 0; needBead[i]; i++) {
        have[needBead[i]]--;
    }
    int extra = 0;
    int lack = 0;
    for (int i = 0; i < 128; i++) {
        if (have[i] > 0) extra += have[i];
        else if (have[i] < 0) lack -= have[i];
    }
    if (lack == 0) {
        printf("Yes %d\n", extra);
    } else {
        printf("No %d\n", lack);
    }
    return 0;
}
