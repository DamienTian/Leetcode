/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
// Solution 1: No DP
// class NumArray {
// public:
//     NumArray(vector<int>& nums) {
//         array = move(nums);
//         // move(nums.begin(), nums.end(), array.begin());
//     }
    
//     int sumRange(int left, int right) {
//         if(left < 0) { left = 0; }
//         if(right >= array.size()) { right = array.size() - 1; }
//         int result = 0;
//         // for(auto it = array.begin() + left; it != array.begin() + right; ++it){
//         //     result += *it;
//         // }
//         for(int i = left; i <= right; ++i){
//             result += array[i];
//         }
//         return result;
//     }
// private:
//     vector<int> array;
// };

// Solution 2: use DP to stores the value of range sum
//  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-303-range-sum-query-immutable/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }
        sums.push_back(nums[0]); 
        for(int i = 1; i < nums.size(); ++i){
            sums.push_back(nums[i] + sums[i - 1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return sums[right];
        }
        return sums[right] - sums[left-1];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

