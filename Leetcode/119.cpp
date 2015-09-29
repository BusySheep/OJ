class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return vector<int>();
        vector<int> result = {1};
        vector<int> old = result;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                result[j] = old[j - 1] + old[j];
            }
            result.push_back(1);
            old = result;
        }
        return result;
    }
};