/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: two ptrs with additional space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = 0, n2 = 0;
        vector<int> result;
        while(n1 < m && n2 < n){
            if(nums1[n1] < nums2[n2]){
                result.push_back(nums1[n1++]);
            }
            else{
                result.push_back(nums2[n2++]);
            }
        }
        if(n1 < m)
            result.insert(result.end(), nums1.begin() + n1, nums1.begin() + n1 + (m - n1));
        else if(n2 < n)
            result.insert(result.end(), nums2.begin() + n2, nums2.begin() + n2 + (n - n2));
        nums1 = result;
    }

    // Solution 2: three pointers without additional space
    //  ref: https://www.cnblogs.com/grandyang/p/4059650.html
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};
// @lc code=end

