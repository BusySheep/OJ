#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkEnd(vector<int>& nums, int i, int j, int mediaIndex, bool isOdd, double* result) {
        static double first;
        static double second;
        if (i + j == mediaIndex - 1) {
            first = nums[i];
        } else if (i + j == mediaIndex) {
            if (isOdd) {
                *result = nums[i];
                return true;
            }
            second = nums[i];
            *result = ((double)first + second) / 2;
            return true;
        }
        return false;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        bool isOdd = (nums1.size() + nums2.size()) % 2 == 1;
        int mediaIndex = (int)(nums1.size() + nums2.size()) / 2;
        double result;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                bool isEnd = checkEnd(nums1, i, j, mediaIndex, isOdd, &result);
                if (isEnd) {
                    return result;
                }
                i++;
            } else {
                bool isEnd = checkEnd(nums2, j, i, mediaIndex, isOdd, &result);
                if (isEnd) {
                    return result;
                }
                j++;
            }
        }
        while (i < nums1.size()) {
            bool isEnd = checkEnd(nums1, i, j, mediaIndex, isOdd, &result);
            if (isEnd) {
                return result;
            }
            i++;
        }
        while (j < nums2.size()) {
            bool isEnd = checkEnd(nums2, j, i, mediaIndex, isOdd, &result);
            if (isEnd) {
                return result;
            }
            j++;
        }
        return -1;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums1(n, 0);
    vector<int> nums2(m, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums2[i]);
    }
    printf("%lf\n", Solution().findMedianSortedArrays(nums1, nums2));
    return 0;
}