#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string source;
int pointer = 0;
string target;
vector<char> temp;
vector<char> stack;
vector<vector<char> > ans;
vector<char> solution;

void dfs(int index) {
    if (index == 2 * target.length()) {
        ans.push_back(solution);
        return;
    }
    
    //in
    if (pointer < source.length()) {
        solution.push_back('i');
        stack.push_back(source[pointer]);
        pointer++;
        dfs(index + 1);
        pointer--;
        stack.pop_back();
        solution.pop_back();
    }
    
    //out
    if (stack.size() > 0) {
        char t = stack[stack.size() - 1];
        solution.push_back('o');
        stack.pop_back();
        temp.push_back(t);
        if (t == target[temp.size() - 1]) {
            dfs(index + 1);
        }
        stack.push_back(t);
        solution.pop_back();
        temp.pop_back();
    }
}

int main(void) {
    char temp1[1000];
    char temp2[1000];
    while (scanf("%s%s", temp1, temp2) != EOF) {
        source = temp1;
        target = temp2;
        cout << '[' << endl;
        if (source.length() == target.length()) {
            ans.clear();
            solution.clear();
            temp.clear();
            stack.clear();
            pointer = 0;
            dfs(0);
            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < ans[i].size(); j++) {
                    printf("%c ", ans[i][j]);
                }
                puts("");
            }
        }
        cout << ']' << endl;
    }
}
