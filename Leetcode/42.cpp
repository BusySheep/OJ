class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> behindMax(height.size(), 0); // the maximum of range [i + 1, height.size())
        for (int i = height.size() - 2; i >= 0; i--) {
            behindMax[i] = max(height[i + 1], behindMax[i + 1]);
        }
        int result = 0;
        for (int i = 0; i < height.size() - 1; ) {
            int waterHeight = min(behindMax[i], height[i]);
            for (i++; height[i] < waterHeight; i++) {
                result += waterHeight - height[i];
            }
        }
        return result;
    }
};