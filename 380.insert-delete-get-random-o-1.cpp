/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
//#include "dummyHead.h"

// Solution 1: Set
//  note: using advance() in getRandom() gives it average O(1) time
class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(s.count(val))
            return false;
        s.emplace(val);
        return true;
    }
    
    bool remove(int val) {
        if(!s.count(val))
            return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        // ref: https://stackoverflow.com/questions/3052788/how-to-select-a-random-element-in-stdset
        int randomIndex = rand() % s.size();
        unordered_set<int>::iterator it = s.begin();
        advance(it, randomIndex);
        return *it;
    }

private:
    unordered_set<int> s;
};

// Solution 2: Hashmap + vector
//  ref: https://www.cnblogs.com/grandyang/p/5740864.html
//  TODO: skip for first time.

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

