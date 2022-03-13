/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 */

// @lc code=start

class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        total += val;
        q.push(val);
        while(q.size() > size){
            int front = q.front();
            q.pop();
            total -= front;
        }
        return total / q.size();
    }

private:
    queue<int> q;
    int size;
    double total = 0;
};

// @lc code=end