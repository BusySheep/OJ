//
//  main.cpp
//  PAT
//
//  Created by 柯瀚仰 on 15/3/13.
//  Copyright (c) 2015年 柯瀚仰. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Edge {
    int to;
    int cap;
    int rev;
};

vector<Edge> g[1002];
bool visited[1002];

void addEdge(int from, int to, int cap) {
    g[from].push_back((Edge){to, cap, (int)g[to].size()});
    g[to].push_back((Edge){from, 0, (int)g[from].size() - 1});
    
}

int dfs(int v, int t, int f) {
    if (v == t) {
        return f;
    }
    visited[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        Edge &e = g[v][i];
        if (!visited[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    const int INF = 1000000000;
    int flow = 0;
    for (; ; ) {
        memset(visited, false, sizeof(visited));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
    return flow;
}

int main(void) {
    map<string, int> number;
    int count = 0;
    string source;
    string destination;
    int n;

    cin >> source >> destination >> n;
    number[source] = count++;
    number[destination] = count++;
    for (int i = 0; i < n; i++) {
        string s;
        string d;
        int cap;
        cin >> s >> d >> cap;
        if (number.count(s) == 0) {
            number[s] = count++;
        }
        if (number.count(d) == 0) {
            number[d] = count++;
        }
        addEdge(number[s], number[d], cap);
    }
    printf("%d\n", maxFlow(number[source], number[destination]));
    return 0;
}

