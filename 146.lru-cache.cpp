/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

//#include "dummyHead.h"

// Solution: Hash + List
//  ref: https://www.cnblogs.com/grandyang/p/4587511.html
//  note: this is a HARD problem originally 
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity){}
    
    int get(int key) {
        if(!m.count(key))
            return -1;
        auto it = m[key];
        // put at the front to indicate the most recent used
        l.splice(l.begin(), l, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            l.erase(m[key]);
        }
        // put at the front to indicate the most recent used
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        // erase the last element (the least recently used)
        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

