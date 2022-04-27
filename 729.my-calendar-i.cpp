/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start

// #include "dummyHead.h"

class MyCalendar {
public:
    MyCalendar() {}
    
    // Linear search
    // bool book(int start, int end) {
    //     for(const auto& c : calender){
    //         if(!notOverlap(start, end, c.first, c.second))
    //             return false;
    //     }
    //     calender.insert({start, end});
    //     return true;
    // }

    // Optimized (binary search)
    //  ref: https://www.cnblogs.com/grandyang/p/7920253.html
    bool book(int start, int end) {
        // find the lower bound of the insert start time
        auto it = calender.lower_bound(start);
        // if lower bound's start time happened before new end time, return false
        if(it != calender.end() && it->first < end)
            return false;
        // if previous of lower bound's end time is after new start time, return false
        if(it != calender.begin() && prev(it)->second > start)
            return false;
        calender.insert({start, end});
        return true;
    }

private:
    map<int, int> calender;
    bool notOverlap(int s1, int e1, int s2, int e2){
        return (s1 <= s2 && e1 <= s2) || (s1 >= e2 && e1 >= e2);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

