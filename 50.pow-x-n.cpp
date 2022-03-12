/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // NOTE: Failed Solution but right in Algorithm
    // double myPow(double x, int n) {
    //     if(abs(n) == 0)
    //         return 1.0;
    //     return ((n < 0) ? 1/x : x) * myPow(x, (n < 0) ? n+1 : n-1);
    // }

    // Solution 1: divide and conqure (recursive)
    //  ref: https://www.cnblogs.com/grandyang/p/4383775.html
    // double myPow(double x, int n) {
    //     if(n == 0)
    //         return 1;
    //     double xx = myPow(x, n / 2);
    //     if(n % 2 == 0)
    //         return xx * xx;
    //     if(n > 0)
    //         return xx * xx * x;
    //     else
    //         return xx * xx / x;
    // }

    // Solution 2: divide and conqure (iterative)
    double myPow(double x, int n)
    {
        double result = 1.0;
        for (int i = n; i != 0; i /= 2)
        {
            
            if (i % 2 != 0)
            {
                result *= x;
            }

            x *= x;
            
            // cout << "i: " << i << endl;
            // cout << "result = " << result << endl;
            // cout << "x = " << x << endl;
        }
        return n < 0 ? 1 / result : result;
    }
};
// @lc code=end
