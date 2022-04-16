/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: stack
    //  ref: https://www.cnblogs.com/grandyang/p/4570699.html
    int calculate(string s) {
        int result = 0;
        int sign = 1;   // 1 for '+', -1 for '-'
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0'){    // digit
                int num = 0;
                while(i < s.size() && s[i] >= '0')
                    num = 10 * num + (s[i++] - '0');
                result += sign * num;
                --i;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '('){
                st.push(result);// push current result 
                st.push(sign);  // push current sign
                result = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                result *= st.top(); // result * sign before ()
                st.pop(); 
                result += st.top(); // result += result outside of ()
                st.pop();
            }
        }

        return result;
    }
};
// @lc code=end

