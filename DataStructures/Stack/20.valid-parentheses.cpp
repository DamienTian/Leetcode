/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
//#include "dummyHead.h"

// The most recent practice
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            switch (c)
            {
            case(')'):
                !st.empty() && st.top() == '(' ? st.pop() : st.push(c);
                break;
            case(']'):
                !st.empty() && st.top() == '[' ? st.pop() : st.push(c);
                break;
            case('}'):
                !st.empty() && st.top() == '{' ? st.pop() : st.push(c);
                break;
            default:
                st.push(c);
                break;
            }
        }
        return st.empty();
    }
};

// Solution: stack
// class Solution {
// public:
//     bool isValid(string s) {
//         unordered_map<char, char> m ({
//             {')', '('}, {']', '['}, {'}', '{'}
//         });
//         stack<char> st;
//         for(char c : s){
//             if(!st.empty() && m[c] == st.top())
//                 st.pop();
//             else
//                 st.push(c);
//         }
//         return st.empty();
//     }
// };
// @lc code=end

