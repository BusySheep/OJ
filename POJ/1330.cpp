//
//  main.cpp
//  POJ
//
//  Created by 柯瀚仰 on 15/3/14.
//  Copyright (c) 2015年 柯瀚仰. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dijSet[10000];

void initialDijSet(int n) {
    for (int i = 0; i < n; i++) {
        dijSet[i] = i;
    }
}

int getRoot(int node) {
    if (dijSet[node] == node) {
        return node;
    }
    else {
        return dijSet[node] = getRoot(dijSet[node]);
    }
}

void merge(int a, int b) {
    int rA = getRoot(a);
    int rB = getRoot(b);
    if (rA != rB) {
        dijSet[rB] = rA;
    }
}

int findNCA(int node, int a, int b, vector<int> tree[], vector<bool>& visited) {
    int NCA = -1;
    for (int i = 0; i < tree[node].size(); i++) {
        NCA = findNCA(tree[node][i], a, b, tree, visited);
        if (NCA != -1) {
            return NCA;
        }
        merge(node, tree[node][i]);
    }
    visited[node] = true;
    if (node == a && visited[b]) {
        return getRoot(b);
    }
    else if (node == b && visited[a]) {
        return getRoot(a);
    }
    else {
        return -1;
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> tree[10000];
        vector<bool> rootFlag(n, true);
        vector<bool> visited(n, false);
        initialDijSet(n);
        for (int i = 0; i < n - 1; i++) {
            int parent;
            int child;
            scanf("%d%d", &parent, &child);
            parent--;
            child--;
            tree[parent].push_back(child);
            rootFlag[child] = false;
        }
        int root;
        for (int i = 0; i < n; i++) {
            if (rootFlag[i] == true) {
                root = i;
                break;
            }
        }
        int a;
        int b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        printf("%d\n", findNCA(root, a, b, tree, visited) + 1);
    }
    return 0;
}



