/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start

// #include "dummyHead.h"

// Most rencent practice
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int count = 0; // count left parethese
        for(char c : s){
            if(c == '('){
                st.push(c);
                count++;
            }
            else if(c == ')'){
                if(count > 0){
                    st.push(c);
                    count--;
                }
            }
            else
                st.push(c);
        }

        string result = "";
        while(!st.empty()){
            if(st.top() == '(' && count > 0){
                st.pop();
                count--;
            }
            else{
                result.push_back(st.top());
                st.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// @lc code=end

