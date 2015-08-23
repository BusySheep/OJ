#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < m && j < n) {
            if (nums1[i + n] < nums2[j]) {
                nums1[count++] = nums1[i + n];
                i++;
            } else {
                nums1[count++] = nums2[j];
                j++;
            }
        }
        while (i < m) {
            nums1[count++] = nums1[i + n];
            i++;
        }
        while (j < n) {
            nums1[count++] = nums2[j];
            j++;
        }
    }
};

int main() {
    int m;
    int n;
    cin >> m;
    vector<int> nums1(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    cin >> n;
    vector<int> nums2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
        nums1.push_back(0);
    }
    Solution().merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << ' ';
    }
    cout << endl;
    return 0;
}