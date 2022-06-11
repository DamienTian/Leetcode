/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=left

// #include "dummyHead.h"

class Solution {
public:
    string minWindow(string s, string t) {
        return slidingWindowHashmap(s, t);
    }

private:
    // Solution 1: sliding window (with Hashmap)
    //  ref: https://www.cnblogs.com/grandyang/p/4340948.html
    string slidingWindowHashmap(string s, string t){
        string result = "";

        // record how many char need to be matched in T
        unordered_map<char, int> recordT;
        for(const char& c : t)
            recordT[c]++;
        
        // left index of substring
        int left = 0;
        // count matched char in s
        int matched = 0;
        // current min len
        int minLen = INT_MAX;

        // iterate s
        for(int i = 0; i < s.size(); ++i){
            // count every matched char in t
            if(--recordT[s[i]] >= 0)
                ++matched;
            
            // if matched all char in t, update result and slide left boundary to right
            while(matched == t.size()){
                // update min length substr
                if(minLen > i - left + 1){
                    minLen = i - left + 1;
                    result = s.substr(left, minLen);
                }
                // slide window: move left boundary to right, and if removed char is essential to t, deduce matched
                if(++recordT[s[left++]] > 0)
                    --matched;
            }
        } 
        return result;
    }
};
// @lc code=end

