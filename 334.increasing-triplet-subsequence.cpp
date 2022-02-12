/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * Category: Greedy
 */

// @lc code=start

// ref: https://www.youtube.com/watch?v=xV_AS08-OeA&list=PLLuMmzMTgVK5Igci8P3d88XpoyeIA1Fl-&index=12
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }

        int first = 0, second = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (second == -1)
            {
                if(nums[i] <= nums[first]){
                    first = i;
                }
                else{
                    second = i;
                }
            }
            else
            {
                if(nums[i] <= nums[first]){
                    first = i;
                    //second = -1;
                }
                else if(nums[i] > nums[first] && nums[i] <= nums[second]){
                    second = i;
                }
                else if(nums[i] > nums[second]){
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end
