/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    // Solution: Divide and Conqure
    //  ref: https://www.cnblogs.com/grandyang/p/12287146.html (code) + https://blog.csdn.net/Hanx09/article/details/108277448 (idea)
    vector<int> beautifulArray(int n) {
        vector<int> result {1};
        while(result.size() < n){
            vector<int> temp;

            // odd number part build
            for(auto r : result){
                if(r * 2 - 1 <= n){ 
                    temp.push_back(r * 2 - 1);
                }
            }

            // even number part build
            for(auto r : result){
                if(r * 2 <= n){ 
                    temp.push_back(r * 2 );
                }
            }

            result = temp;
        }

        return result;
    }
};
// @lc code=end

