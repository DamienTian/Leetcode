/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: Binary Search
//  ref: https://www.cnblogs.com/grandyang/p/9784690.html
class Solution {
public:
    Solution(vector<int>& w) {
        sumWeight = w;
        for(int i = 1; i < w.size(); ++i){
            sumWeight[i] = sumWeight[i - 1] + w[i]; 
        }
    }
    
    int pickIndex() {
        int totalWeight = sumWeight.back();
        int random = rand() % totalWeight;
        int left = 0, right = sumWeight.size() - 1;

        // return the first larger sum weight element than random index
        while(left < right){
            int mid = left + (right - left) / 2;
            if(sumWeight[mid] <= random)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }

private:
    vector<int> sumWeight;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

