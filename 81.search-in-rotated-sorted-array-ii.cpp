/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    // Solution: Binary Search
    //  ref: https://www.cnblogs.com/grandyang/p/4325840.html
    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            cout << "mid = " << mid << " left = " << left << " right = " << right << endl;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < nums[right])
            {
                cout << "right sorted" << endl;
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] > nums[right])
            {
                cout << "left sorted" << endl;
                if (nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            //  Note: unlike #33, this problem has duplicated nums, so if we see duplicated num (nums[mid] == nums[right]), move right to left by 1             
            else
                --right;
        }
        return false;
    }
};
// @lc code=end
