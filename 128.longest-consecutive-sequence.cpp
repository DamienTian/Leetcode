/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// #include "dummyHead.h"

// NOTE: Solution 1 is faster, but hard to understand, Solution 2 is O(nlogn)
class Solution
{
public:
    // Solution 1: Hashmap (online)
    //  ref: https://zxi.mytechroad.com/blog/hashtable/leetcode-128-longest-consecutive-sequence/
    // int longestConsecutive(vector<int> &nums)
    // {
    //     unordered_map<int, int> m;
    //     int result = 0;
    //     for(int num : nums){
    //         if(!m.count(num)){
    //             // left and right indicates the length records on consequtive numbers' boundaries,
    //             //  the length is records on the left and right end of the numbers.
    //             //  ref provides explaination
    //             int left = m.count(num - 1) ? m[num - 1] : 0;
    //             int right = m.count(num + 1) ? m[num + 1] : 0;
    //             int newLength = left + right + 1;

    //             m[num] = m[num - left] = m[num + right] = newLength;
    //             result = max(result, newLength);
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: Set (offline)
    //  ref: https://zxi.mytechroad.com/blog/hashtable/leetcode-128-longest-consecutive-sequence/
    //  note: Grandyang provides a better brutal version: https://www.cnblogs.com/grandyang/p/4276225.html (Solution 1)
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;
        for(int n : nums){
            if(!s.count(n - 1)){
                int l = 0;
                while(s.count(n++)){
                    ++l;
                }
                result = max(result, l);
            }
        }
        return result;
    }
};
// @lc code=end
