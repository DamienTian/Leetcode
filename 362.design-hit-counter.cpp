/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 */

// @lc code=start
//#include "dummyHead.h"

// Solution 1: queue
class HitCounter {
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!q.empty() && timestamp - q.front() >= 300)
            q.pop();
        return q.size();
    }

private:
    queue<int> q;
};

// Solution 2: two fixed size vectors
//  ref: https://www.cnblogs.com/grandyang/p/5605552.html
//  note: this could solve the number of hits per second could be huge
// class HitCounter {
// public:
//     HitCounter() {
//         times.resize(300);
//         hits.resize(300);
//     }
    
//     void hit(int timestamp) {
//        int index = timestamp % 300;
//        if(times[index] != timestamp){
//            times[index] = timestamp;
//            hits[index] = 1;
//        }
//        else{
//            ++hits[index];
//        } 
//     }
    
//     int getHits(int timestamp) {
//         int result = 0;
//         for(int i = 0; i < times.size(); ++i){
//             if(timestamp - times[i] < 300){
//                 result += hits[i];
//             }
//         }
//         return result;
//     }

// private:
//     //use two fixed size vector to store following records in 300 seconds:
//     //      - times: timestamp 
//     //      - hits: number of hits happen at the timestamp
//     vector<int> times, hits;
// };

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

// @lc code=end