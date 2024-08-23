/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
//#include "dummyHead.h"

// most recent practice
//  Solution 1: 2 stacks
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if(minS.empty() || val <= minS.top()){
            minS.push(val);
        }
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        if(t == minS.top()){
            minS.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }

private:
    stack<int> s;
    stack<int> minS; // record min val
};

// Solution 2: single stack
//  ref: https://www.cnblogs.com/grandyang/p/4091064.html
// class MinStack {
// public:
//     MinStack() {
//         min = numeric_limits<int>::max();
//     }
    
//     void push(int val) {
//         // push the next min twice to keep the original order
//         if(val <= min){
//             s.push(min);
//             min = val;
//         }
//         s.push(val);
//     }
    
//     void pop() {
//         // when pop, pop the next min as well since it was pushed twice
//         int top = s.top();
//         s.pop();
//         if(top == min){
//             min = s.top();
//             s.pop();
//         }
//     }
    
//     int top() {
//         return s.top();
//     }
    
//     int getMin() {
//         return min;
//     }

// private:
//     stack<int> s;
//     int min;
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



