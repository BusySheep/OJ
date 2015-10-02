class Solution {
private:
    vector<int> fact = {1};
    vector<int> rest;
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fact.push_back(*fact.rbegin() * i);
        }
        for (int i = 1; i <= n; i++) {
            rest.push_back(i);
        }
    }
    int getIndexThRest(int index) {
        int result = rest[index];
        rest.erase(rest.begin() + index);
        return result;
    }
public:
    string getPermutation(int n, int k) {
        init(n);
        string result;
        k--;
        while (n) {
            int index = k / fact[n - 1];
            result += '0' + getIndexThRest(index);
            k -= index * fact[n - 1];
            n--;
        }
        return result;
    }
};