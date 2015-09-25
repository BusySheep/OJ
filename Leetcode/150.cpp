class Solution {
private:
    bool isNumber(string& str) {
        return str[0] == '-' && str.length() > 1 || str[0] >='0' && str[0] <= '9';
    }
    int calculate(int num1, int num2, string& oper) {
        switch (oper[0]) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return num1 / num2;
            default: return 0;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i])) {
                operands.push(stoi(tokens[i]));
            } else {
                int num2 = operands.top();
                operands.pop();
                int num1 = operands.top();
                operands.pop();
                int result = calculate(num1, num2, tokens[i]);
                operands.push(result);
            }
        }
        return operands.top();
    }
};