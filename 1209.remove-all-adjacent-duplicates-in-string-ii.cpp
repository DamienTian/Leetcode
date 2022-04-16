/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: stack
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c : s){
            if(st.empty() || st.top().first != c)
                st.push({c, 1});
            else if(st.top().first == c)
                st.top().second++;
            if(st.top().second >= k)
                st.pop();
        }
        string result;
        while(!st.empty()){
            auto output = st.top();
            st.pop();
            for(int i = 0; i < output.second; ++i)
                result.push_back(output.first);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

