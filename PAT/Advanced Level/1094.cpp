#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int m;
    scanf("%d%d", &n, &m);
    vector< vector<int> > family(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int id;
        int k;
        scanf("%d%d", &id, &k);
        id--;
        for (int j = 0; j < k; j++) {
            int childId;
            scanf("%d", &childId);
            childId--;
            family[id].push_back(childId);
        }
    }
    queue< pair<int, int> > q;
    q.push(make_pair(0, 1));
    int largestGeneration;
    int largestPopulation = 0;
    int currentGeneration;
    int currentPopulation = 0;
    while (!q.empty()) {
        int id = q.front().first;
        int generation = q.front().second;
        q.pop();
        if (generation == currentGeneration) {
            currentPopulation ++;
        } else {
            currentGeneration = generation;
            currentPopulation = 1;
        }
        if (largestPopulation < currentPopulation) {
            largestPopulation = currentPopulation;
            largestGeneration = currentGeneration;
        }
        for (int i = 0; i < family[id].size(); i++) {
            q.push(make_pair(family[id][i], generation + 1));
        }
    }
    printf("%d %d\n", largestPopulation, largestGeneration);
    return 0;
}