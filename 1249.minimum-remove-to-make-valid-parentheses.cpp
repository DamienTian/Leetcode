/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: stack
    //  note: check https://www.cnblogs.com/grandyang/p/15515997.html solution 2
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 'a' && s[i] <= 'z')
                continue;
            if(s[i] == '(')
                st.push({s[i], i});
            else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '(')
                    st.pop();
                else
                    st.push({s[i], i});
            }
        }
        unordered_set<int> removedIndex;
        while(!st.empty()){
            removedIndex.insert(st.top().second);
            st.pop();
        }
        string result;
        for(int i = 0; i < s.length(); ++i){
            if(!removedIndex.count(i))
                result.push_back(s[i]);
        }
        return result;
    }
};
// @lc code=end

