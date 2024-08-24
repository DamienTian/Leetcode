/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
//#include "dummyHead.h"

// Solution: two stacks
//  ref: https://www.cnblogs.com/grandyang/p/4626238.html

// most recent practice
//  Time complexity: amortized O(1)
class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        shiftElements();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        shiftElements();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

    void shiftElements() {
        // s2 in FIFO order, and if not empty, means still have elements, return
        if(!s2.empty())
            return;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
private:
    // s1: take new elements
    // s2: use to get the top element
    stack<int> s1, s2;    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

