/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: Sliding Window + TreeSet
    //  ref: https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/ 
    // int longestSubarray(vector<int>& nums, int limit) {
    //     int result = 0;
    //     int left = 0;
    //     // use tree set to keep the order of collection
    //     multiset<int> s;
    //     for(int right = 0; right < nums.size(); ++right){
    //         s.insert(nums[right]);
    //         // do window sliding
    //         while(*rbegin(s) - *begin(s) > limit)
    //             s.erase(s.equal_range(nums[left++]).first);
    //         result = max(right - left + 1 , result);
    //     }
    //     return result;
    // }

     // Solution 2: Sliding Window + Dual Monotonic Queue
    //  ref: https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/ 
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQ, maxQ;
        int result = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); ++right){
            while(!minQ.empty() && nums[right] < minQ.back())
                minQ.pop_back();
            while(!maxQ.empty() && nums[right] > maxQ.back())
                maxQ.pop_back();
            minQ.push_back(nums[right]);
            maxQ.push_back(nums[right]);
            // slide window 
            while(maxQ.front() - minQ.front() > limit){
                if(maxQ.front() == nums[left])  maxQ.pop_front();
                if(minQ.front() == nums[left])  minQ.pop_front();
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end

