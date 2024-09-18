/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
//#include "dummyHead.h"

// Solution 1: array (std::vector)
// class BrowserHistory {
// public:
//     BrowserHistory(string homepage) {
//         history.push_back(homepage);
//         current = 0;
//     }
    
//     void visit(string url) {
//         history.erase(history.begin() + current + 1, history.end());
//         history.push_back(url);
//         current = history.size() - 1;
        
//     }
    
//     string back(int steps) {
//         current = (current - steps) >= 0 ? current - steps : 0;
//         return history[current];
//     }
    
//     string forward(int steps) {
//         current = (current + steps) < history.size() ? current + steps : history.size()-1;
//         return history[current];
//     }

// private:
//     vector<string> history;
//     int current;
// };

// Solution 2: two stacks (the most recent practice)
//  ref: https://www.youtube.com/watch?v=-a3np7BO2zY
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        backSt.push(homepage);
    }
    
    void visit(string url) {
        backSt.push(url);
        while(!forwardSt.empty())
            forwardSt.pop();
    }
    
     string back(int steps) {
        while (steps > 0 && backSt.size() > 1) {  
            string moveToForward = backSt.top();
            backSt.pop();
            forwardSt.push(moveToForward);
            --steps;
        }
        return backSt.top();
    }
    
    string forward(int steps) {
        while (steps > 0 && !forwardSt.empty()) {  
            string moveToBack = forwardSt.top();
            forwardSt.pop();
            backSt.push(moveToBack);
            --steps;
        }
        return backSt.top();
    }

private:
    stack<string> backSt, forwardSt;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

