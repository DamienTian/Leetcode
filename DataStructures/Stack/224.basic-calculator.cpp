/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start

//#include "dummyHead.h"

// most recent practice
class Solution {
public:
    int calculate(string s) {
        int result = 0, op = 1; // op(sign): 1 as +, -1 as -;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0'){
                int num = 0;
                while(s[i] >= '0' && i < s.size())
                    num = num * 10 + (s[i++] - '0');
                result += op * num;
                --i;
            }
            else if(s[i] == '+')
                op = 1;
            else if(s[i] == '-')
                op = -1;
            else if(s[i] == '(') { // push things into stack
                st.push(result);
                st.push(op);
                result = 0;
                op = 1;
            }
            else if(s[i] == ')'){ // pop things and calculate
                result *= st.top(); st.pop(); // apply op(sign)
                result += st.top(); st.pop(); // add previous result
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     // Solution: stack
//     //  ref: https://www.cnblogs.com/grandyang/p/4570699.html
//     int calculate(string s) {
//         int result = 0;
//         int sign = 1;   // 1 for '+', -1 for '-'
//         stack<int> st;
//         for(int i = 0; i < s.size(); ++i){
//             if(s[i] >= '0'){    // digit
//                 int num = 0;
//                 while(i < s.size() && s[i] >= '0')
//                     num = 10 * num + (s[i++] - '0');
//                 result += sign * num;
//                 --i;
//             }
//             else if(s[i] == '+')
//                 sign = 1;
//             else if(s[i] == '-')
//                 sign = -1;
//             else if(s[i] == '('){
//                 st.push(result);// push current result 
//                 st.push(sign);  // push current sign
//                 result = 0;
//                 sign = 1;
//             }
//             else if(s[i] == ')'){
//                 result *= st.top(); // result * sign before ()
//                 st.pop(); 
//                 result += st.top(); // result += result outside of ()
//                 st.pop();
//             }
//         }
//         return result;
//     }
// };
// @lc code=end

