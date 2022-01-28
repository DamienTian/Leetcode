/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
    // Failed solution: Time Limit Exceeded
    // int longestSubsequence(vector<int>& arr, int difference) {
    //     int n = arr.size();
    //     vector<int> dp(n, 1);
    //     int result = 1;
    //     for(int i = 1; i < n; ++i){
    //         for(int j = i - 1; j >= 0; --j){
    //             int t = arr[i] - difference;
    //             if(t == arr[j]){
    //                 dp[i] = max(dp[j] + 1, dp[i]);
    //                 result = max(dp[i], result);
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution DP
    //  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1218-longest-arithmetic-subsequence-of-given-difference/
    //  key: use hashtable
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int result = 0;
        for(int n : arr){
            result = max(result, dp[n] = dp[n - difference] + 1);
        }
        return result;
    }
};
// @lc code=end

