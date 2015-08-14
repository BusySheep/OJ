#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string* temp = new string[numRows];
        int flag = numRows == 1 ? 0 : 1;
        for (int i = 0, count = 0; count < s.length(); count++) {
        	temp[i] += s[count];
        	i += flag;
        	if (i == 0 || i == numRows - 1) {
        		flag = -flag;
        	}
        }
        string result;
        for (int i = 0; i < numRows; i++) {
        	result += temp[i];
        }
        return result;
    }
};

int main() {
	string s;
	cin >> s;
	int numRows;
	cin >> numRows;
	cout << Solution().convert(s, numRows);
	return 0;
}