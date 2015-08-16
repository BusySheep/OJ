#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool hasStar(int index, string& p) {
		return index < p.length() - 1 && p[index + 1] == '*';
	}
	string pre(string p) {
		string result;
		for (int i = 0; i < p.length(); ) {
			result.push_back(p[i]);
			if (hasStar(i, p)) {
				result.push_back(p[i + 1]);
				while (i < p.length() - 2 && hasStar(i + 2, p) && p[i] == p[i + 2]) {
					i += 2;
				}
				i += 2;
			} else {
				i++;
			}
		}
		return result;
	}
    bool isMatch(string s, string p) {
    	p = pre(p);
        queue< pair<int, int> > q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
        	pair<int, int> state = q.front();
        	q.pop();
        	int si = state.first;
        	int pi = state.second;

        	// check end
        	if (si == s.length() && pi == p.length()) {
        		return true;
        	} else if (si >= s.length()) {
        		int i;
        		for (i = pi; i < p.length(); i++) {
        			if (!hasStar(i, p)) {
        				break;
        			} else {
        				i++;
        			}
        		}
        		if (i < p.length()) {
        			continue;
        		} else {
        			return true;
        		}
        	} else if (pi >= p.length()) {
        		continue;
        	}

        	if (hasStar(pi, p)) {
        		if (p[pi] == '.') {
        			q.push(make_pair(si + 1, pi));
        			q.push(make_pair(si, pi + 2));
        		} else {
        			if (s[si] == p[pi]) {
        				q.push(make_pair(si + 1, pi));
        				q.push(make_pair(si, pi + 2));
        			} else {
        				q.push(make_pair(si, pi + 2));
        			}
        		}
        	} else {
        		if (p[pi] == '.') {
        			q.push(make_pair(si + 1, pi + 1));
        		} else {
        			if (s[si] == p[pi]) {
        				q.push(make_pair(si + 1, pi + 1));
        			} else {
        				// do nothing, end this path
        			}
        		}
        	}
        }
        return false;
    }
};
int main() {
	string s, p;
	cin >> s >> p;
	cout << Solution().isMatch(s, p) << endl;
	return 0;
}