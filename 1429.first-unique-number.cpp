/*
 * @lc app=leetcode id=1429 lang=cpp
 *
 * [1429] Zigzag Iterator
 */
// @lc code=start
//#include "dummyHead.h"

// Solution: Queue & Hash 
//  ref: https://leetcode.com/problems/first-unique-number/solution/
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(int n : nums){
            if(!records.count(n)){
                records.emplace(n, 1);
                uniques.push(n);
            }
            else{
                records[n] += 1;
            }
        }
    }
    
    int showFirstUnique() {
        while(!uniques.empty()){
            if(records[uniques.front()] == 1)
                return uniques.front();
            uniques.pop();
        }
        return -1;
    }
    
    void add(int value) {
        if(!records.count(value)){
            records.emplace(value, 1);
            uniques.push(value);
        }
        else{
            records[value] += 1;
        }
    }

private:
    unordered_map<int, int> records;
    queue<int> uniques;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

// @lc code=end