/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
//#include "dummyHead.h"

// Most recent practice
// Solution: stack

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        for(string t : tokens){
            if(!isOperator(t)) {
                s.push(stoi(t));
            }
            else{
                int j = s.top(); s.pop();
                int i = s.top(); s.pop();
                int r = compute(i, j, t);
                s.push(r);
            }
        }
        result = s.top(); 
        return result;
    }

private:
    bool isOperator(const string c) {
         return c == "+" || c == "-" || c == "*" || c == "/";
    }

    int compute(int i, int j, const string op){
        if(op == "+") return i + j;
        if(op == "-") return i - j;
        if(op == "*") return i * j;
        if(op == "/") return i / j;
        else return 0;
    }

    stack<int> s;
};
// Solution 1: stack
// class Solution
// {
// public:
//     int evalRPN(vector<string> &tokens)
//     {
//         stack<string> s;
//         for (const string &token : tokens)
//         {
//             if (isOperator(token))
//             {
//                 int n1, n2;
//                 for (int i = 0; i < 2; ++i)
//                 {
//                     int n = stoi(s.top());
//                     s.pop();
//                     if (i == 0)
//                         n2 = n;
//                     else if (i == 1)
//                         n1 = n;
//                 }
//                 int result = cal(n1, n2, token);
//                 s.push(to_string(result));
//             }
//             else
//                 s.push(token);
//         }
//         return stoi(s.top());
//     }

//     bool isOperator(string c)
//     {
//         return c == "+" || c == "-" || c == "*" || c == "/";
//     }

//     int cal(int n1, int n2, string oper)
//     {
//         if (oper == "+")
//             return n1 + n2;
//         if (oper == "-")
//             return n1 - n2;
//         if (oper == "*")
//             return n1 * n2;
//         if (oper == "/")
//             return n1 / n2;
//         return 0;
//     }
// };

// Solution 2: recursion (skip, not perfect solution for this problem)
//  ref: https://www.cnblogs.com/grandyang/p/4247718.html
// @lc code=end
