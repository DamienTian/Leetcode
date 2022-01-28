/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 2){
            if(n == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
        int t0 = 0, t1 = 1, t2 = 1;
        int result = 0;
        for(int i = 0; i < n - 2; ++i){
            result = t0 + t1 + t2;
            int temp = t2;
            t2 = result;
            t0 = t1;
            t1 = temp;
        }
        return result;
    }
};
// @lc code=end

