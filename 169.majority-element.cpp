/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: Moore voting
    //  ref: https://www.cnblogs.com/grandyang/p/4233501.html
    //  note: there exist a bit manipulation version in the ref, it checks every digit of each number in nums
    //        to see if the bit match: using 1 << [0-31](32 bits) swift to do bit AND & with each number:
    //              num & (1 << i) != 0
    //        and merge the bit into result if the bit is 1 in the half of the nums, otherwise not merge.
    int majorityElement(vector<int> &nums)
    {
        int result = 0;
        int count = 0;
        for (int n : nums)
        {
            if (count == 0)
            {
                result = n;
                ++count;
            }
            else if(result != n){
                --count;
            }
            else{
                ++count;
            }
        }

        return result;
    }
};
// @lc code=end
