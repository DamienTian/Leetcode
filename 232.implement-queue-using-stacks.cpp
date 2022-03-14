/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
//#include "dummyHead.h"

// Solution: two stacks
//  ref: https://www.cnblogs.com/grandyang/p/4626238.html
class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        _new.push(x);
    }
    
    int pop() {
        shiftStack();
        int val = _old.top();
        _old.pop();
        return val;
    }
    
    int peek() {
        shiftStack();
        return _old.top();
    }
    
    bool empty() {
        return _new.empty() && _old.empty();
    }

    void shiftStack(){
        if(!_old.empty())
            return;
        while(!_new.empty()){
            _old.push(_new.top());
            _new.pop();
        }
    }

private:
    // _new stores all new push in reversed order, when pop() or peek() was called,
    // move all elements into _old in the correct order.
    stack<int> _new, _old;
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

