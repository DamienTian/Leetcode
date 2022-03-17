/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
// #include "dummyHead.h"

class Solution {
public:
    // Solution: Min Heap
    //  ref: https://www.cnblogs.com/grandyang/p/4743837.html
    int nthUglyNumber(int n) {
        // Min heap
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);

        // Loop for n time, only takes the smallest element in Min heap, 
        //  so after n round, the top of the min heap is the result
        //  note: start from i = 1 since 1 has been pushed into pq 
        for(int i = 1; i < n; ++i){
            long t = pq.top();
            pq.pop();
            // remove duplicated elements
            //  note: consider: 2 * 6 == 3 * 4
            while(!pq.empty() && pq.top() == t)
                pq.pop();
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        return pq.top();
    }
};
// @lc code=end

