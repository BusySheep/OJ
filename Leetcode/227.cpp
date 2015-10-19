class Solution {
private:
    unordered_map<char, int> priorities = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    int calculate(int a, int b, char oper) {
        switch (oper) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
        }
    }
    void calculateOneStep() {
        int b = operands.back();
        operands.pop_back();
        int a = operands.back();
        operands.pop_back();
        char oper = operators.back();
        operators.pop_back();
        int tempResult = calculate(a, b, oper);
        operands.push_back(tempResult);
    }
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    vector<char> operators;
    vector<int> operands;
public:
    int calculate(string s) {
        operators.clear();
        operands.clear();
        int current = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isDigit(s[i])) {
                current *= 10;
                current += s[i] - '0';
            } else if (s[i] != ' ') {
                // is an operator
                operands.push_back(current);
                current = 0;
                while (!operators.empty() && priorities[s[i]] <= priorities[operators.back()]) {
                    calculateOneStep();
                }
                operators.push_back(s[i]);
            }
        }
        operands.push_back(current);
        while (!operators.empty()) {
            calculateOneStep();
        }
        return operands.back();
    }
};