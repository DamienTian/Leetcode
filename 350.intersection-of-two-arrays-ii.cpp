/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: Multiset
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     if(nums1.size() > nums2.size())
    //         swap(nums1, nums2);
    //     multiset<int> setToSearch(nums2.begin(), nums2.end());
    //     vector<int> result;
    //     for(const int& n : nums1){
    //         if(setToSearch.count(n)){
    //             setToSearch.erase(setToSearch.lower_bound(n));
    //             result.push_back(n);
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: Hashmap
    //  ref: https://www.cnblogs.com/grandyang/p/5533305.html
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto a : nums1) ++m[a];
        for (auto a : nums2) {
            //if (m[a]-- > 0) res.push_back(a); // the below works the same
            if(m.count(a) && m[a]>0){
                m[a]--;
                res.push_back(a);
            }
        }
        return res;
    }
};
// @lc code=end

