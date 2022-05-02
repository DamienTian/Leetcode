/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: two ptrs
    //  ref: https://www.cnblogs.com/grandyang/p/5852352.html
    //  note: super hard to think about, check the ref for explaination
    int longestSubstring(string s, int k) {
        int result = 0;
        int index = 0;
        int n = s.size();
        while(index + k <= n){
            // use mem to count # of char
            int mem[26] = {0};
            // mask mark if current substring is longest k substring
            int mask = 0;
            // maxindex to update index for outer while loop search
            int maxIndex = index;
            for(int j = index; j < n; ++j){
                int t = s[j] - 'a';
                mem[t]++;
                if(mem[t] < k)
                    mask |= (1 << t);
                else
                    mask &= (~(1 << t));
                if(mask == 0){
                    result = max(result, j - index + 1);
                    maxIndex = j;
                }
            }
            index = maxIndex + 1;
        }
        return result;
    }

    // TODO：Solution 2: two ptrs with time optimization
    // TODO：Solution 3: Divide and Conqure
    //  ref: https://www.cnblogs.com/grandyang/p/5852352.html
};
// @lc code=end

