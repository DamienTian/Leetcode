/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    // Solution 1
    //  ref: https://grandyang.com/leetcode/53/
    // int maxSubArray(vector<int> &nums)
    // {
    //     int result = numeric_limits<int>::min();
    //     int currentSum = 0;
    //     for(int n : nums){
    //         currentSum = max(n, currentSum + n);
    //         result = max(result, currentSum);
    //     }
    //     return result;
    // }

    // Solution 2: Divide and Conquer
    //  ref: https://grandyang.com/leetcode/53/
    // int maxSubArray(vector<int> &nums)
    // {
    //     if(nums.empty()){
    //         return 0;
    //     }
    //     return dc(nums, 0, nums.size() - 1);
    // }

    // IDEA: split the array to half, find the max value of sum in each subarray,
    //       this solution also involve binary search
    int dc(const vector<int> &nums, int left, int right){
        if(left >= right){
            return nums[left];
        }

        // find the mid for binary search, and then array search to half
        int mid = left + (right - left) / 2;
        int leftMax = dc(nums, left, mid - 1);
        int rightMax = dc(nums, mid + 1, right);

        // use mid to travel both left and right to find max sum, and return the max sum of left and right side;
        int currentMax = nums[mid];
        int currentSum = currentMax;
        //  search left side ... 
        for(int i = mid - 1; i >= left; --i){
            currentSum += nums[i];
            currentMax = max(currentMax, currentSum);
        }

        // reassign currentSum and search right side ...
        currentSum = currentMax;
        for(int i = mid + 1; i <= right; ++i){
            currentSum += nums[i];
            currentMax = max(currentMax, currentSum);
        }

        // return the max result among the left, right, and current max
        return max(currentMax, max(leftMax, rightMax));
    }

    // Solution 3: DP
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }
};
// @lc code=end
