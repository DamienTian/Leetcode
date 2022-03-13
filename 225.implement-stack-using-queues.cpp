/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
//#include "dummyHead.h"

// ref: https://www.cnblogs.com/grandyang/p/4568796.html
// Solution 2: use only one queue, costy on push()
//  note: solution 1 leave the top element in the second queue, and quite costy on top()
class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        // the for loop keep the queue in reversed order
        for(int i = 0; i < (int)q.size() - 1; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

