/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start

//#include "dummyHead.h"

// Solution: stack
// Most recent practice 
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> charSt;
        stack<int> countSt;
        for(char c : s){
            if(charSt.empty() || charSt.top() != c){
                charSt.push(c);
                countSt.push(1);
            }
            else if(!charSt.empty() && charSt.top() == c){
                countSt.top()++;
                if(countSt.top() == k){
                    charSt.pop();
                    countSt.pop();
                }
            }
        }

        string result = "";
        while(!charSt.empty()){
            for(int i = 0; i < countSt.top(); ++i)
                 result.push_back(charSt.top());
            /* 
            -- This block will exceed the Memory Limit of LC, even though don't need to reverse result
            while(countSt.top() > 0){
                result = charSt.top() + result; // This will dup result again and again in memory and cause memory waste
                countSt.top()--;
            }
            */
            charSt.pop();
            countSt.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         stack<pair<char, int>> st;
//         for(char c : s){
//             if(st.empty() || st.top().first != c)
//                 st.push({c, 1});
//             else if(st.top().first == c)
//                 st.top().second++;
//             if(st.top().second >= k)
//                 st.pop();
//         }
//         string result;
//         while(!st.empty()){
//             auto output = st.top();
//             st.pop();
//             for(int i = 0; i < output.second; ++i)
//                 result.push_back(output.first);
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }
// };

// @lc code=end

