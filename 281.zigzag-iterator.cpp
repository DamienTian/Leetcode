/*
 * @lc app=leetcode id=281 lang=cpp
 *
 * [281] Cyclic Iterator
 */

// @lc code=start
//#include "dummyHead.h"

// Solution 1: using queue to order element first (mine)
//  note: this method could be costy when the elements are too many when construct the object
// class ZigzagIterator {
// public:
//     ZigzagIterator(const vector<int>& v1, const vector<int>& v2) {
//         int i1 = 0, i2 = 0;
//         while(i1 < v1.size() && i2 < v2.size()){
//             zigzag.push(v1[i1++]);
//             zigzag.push(v2[i2++]);
//         }
//         while(i1 < v1.size()){
//             zigzag.push(v1[i1++]);
//         }
//         while(i2 < v2.size()){
//             zigzag.push(v2[i2++]);
//         }
//     }

//     int next() {
//         int result = zigzag.front();
//         zigzag.pop();
//         return result;
//     }

//     bool hasNext() {
//         return !zigzag.empty();
//     }
// private:
//     queue<int> zigzag;
// };

// Solution 2: using queue to store vector iterators (Grandyang)
//  note: this method could prevent cost on constructing the object
//  ref: https://www.cnblogs.com/grandyang/p/5212785.html
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            zigzag.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty())
            zigzag.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto it = zigzag.front().first;
        auto end = zigzag.front().second;
        // Pop the vector out and push it to the back, so the next vector element can be access, 
        //  so the elements are visited in a zigzag ordered
        zigzag.pop();
        if(it + 1 != end)
            zigzag.push(make_pair(it + 1, end));
        return *it;
    }

    bool hasNext() {
        return !zigzag.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> zigzag;
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

// @lc code=end