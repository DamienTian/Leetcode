/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 */

// @lc code=start

//#include "../dummyHead.h"

class MovingAverage {
public:
    MovingAverage(int size) {
        n = size;
    }
    
    double next(int val) {
        if(q.size() >= n){
            int front = q.front();
            q.pop();
            mNext -= front;
        }
        q.push(val);
        mNext += val;
        return mNext / q.size();
    }
private:
    queue<int> q;
    int n;
    double mNext = 0;
};

// @lc code=end