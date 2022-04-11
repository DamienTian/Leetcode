/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 */

// @lc code=start

// The knows API is defined for you:
// bool knows(int a, int b); 
// #include "dummyHead.h"

class Solution {
public:
    // Solution: Logical Deduction
    int findCelebrity(int n) {
        int result = 0;
        for(int i = 0; i < n; ++i){
            if(knows(result, i))
                result = i;
        }

        for(int i = 0; i < result; ++i){
            if(!knows(i, result) || knows(result, i))
                return -1;
        }

        for(int i = result + 1; i < n; ++i){
            if(!knows(i, result))
                return -1;
        }

        return result;
    }
};

// @lc code=end