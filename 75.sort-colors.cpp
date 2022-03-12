/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    // Solution: sort by two ptrs
    //  ref: https://www.cnblogs.com/grandyang/p/4341243.html
    //  note: since there are only three number in array, we could loop array only once, put all 0 at the beginning, 2 at the end
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        for(int i = 0; i <= blue; ++i){
            if(nums[i] == 0)
                swap(nums[i], nums[red++]);
            else if(nums[i] == 2)
                // note: i-- since the swaped element might be two blue, need to stay at the same pos to check again
                swap(nums[i--], nums[blue--]);
        }
    }
};
// @lc code=end

