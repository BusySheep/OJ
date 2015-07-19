#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    int m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> family(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int id, k;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            int child;
            scanf("%d", &child);
            family[id].push_back(child);
        }
    }
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(1, 1));
    int maxGeneration = 0;
    int maxPopulation = 0;
    int count = 0;
    int lastGeneration = 0;
    while (!bfsQueue.empty()) {
        int id = bfsQueue.front().first;
        int generation = bfsQueue.front().second;
        bfsQueue.pop();
        if (lastGeneration != generation) {
            if (count > maxPopulation) {
                maxPopulation = count;
                maxGeneration = lastGeneration;
            }
            lastGeneration = generation;
            count = 1;
        }
        else {
            count++;
        }
        for (int i = 0; i < family[id].size(); i++) {
            bfsQueue.push(make_pair(family[id][i], generation + 1));
        }
        if (bfsQueue.empty()) {
            if (count > maxPopulation) {
                maxPopulation = count;
                maxGeneration = generation;
            }
        }
    }
    printf("%d %d\n", maxPopulation, maxGeneration);
    return 0;
}
