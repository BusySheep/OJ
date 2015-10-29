class MinStack {
private:
    stack<int> values;
    stack<int> minValues;
public:
    void push(int x) {
        values.push(x);
        if (minValues.empty() || x < minValues.top()) minValues.push(x);
        else minValues.push(minValues.top());
    }

    void pop() {
        values.pop();
        minValues.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minValues.top();
    }
};