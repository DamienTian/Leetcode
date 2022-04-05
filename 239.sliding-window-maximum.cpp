/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: Monotonic queue
//  ref: http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
class MonotonicQueue{
public:
    void push(int e){
        while(!data.empty() && e > data.back())
            data.pop_back();
        data.push_back(e);
    }

    void pop(){
        data.pop_front();
    }

    int max() const {
        return data.front();
    }
private:
    deque<int> data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> result;

        for(int i = 0; i < nums.size(); ++i){
            q.push(nums[i]);
            if(i >= k - 1){
                result.push_back(q.max());
                // only pop the monotonic queue when the max is out of searching range
                if(nums[i - k + 1] == q.max())
                    q.pop();
            }
        }

        return result;
    }
};
// @lc code=end

