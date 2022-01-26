/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start

// Solution 1: Binary Search (no need, just to practice binary search)
// class TimeMap {
// public:
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         if(!timeMap.count(key)){
//             timeMap[key] = {};
//         }

//         int left = 0;
//         int right = timeMap[key].size();
//         while(left < right){
//             int mid = left + (right - left) / 2;
//             if(timeMap[key][mid].first <= timestamp){
//                 left = mid + 1;
//             }
//             else{
//                 right = mid;
//             }
//         }
//         int index = !(right <= 0) ? right: 0;
//         pair<int, string> newTime (timestamp, value);
//         timeMap[key].emplace(timeMap[key].begin() + index, newTime);
//     }
    
//     string get(string key, int timestamp) {
//         if(!timeMap.count(key)){
//             return "";
//         }

//         int left = 0;
//         int right = timeMap[key].size();
//         while(left < right){
//             int mid = left + (right - left) / 2;
//             if(timeMap[key][mid].first <= timestamp){
//                 left = mid + 1;
//             }
//             else{
//                 right = mid;
//             }
//         }
//         int index = !(right <= 0) ? right - 1 : -1;
//         return index < 0 ? "" : timeMap[key][index].second;
//     }

// private:
//     unordered_map<string, vector<pair<int, string>>> timeMap {};
// };

// Solution 2: STL + map of maps
//  ref: https://www.cnblogs.com/grandyang/p/14195356.html
// NOTE: this problem is about testing data structure, not search
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace(timestamp, move(value));
    }
    
    string get(string key, int timestamp) {
        auto it = timeMap[key].upper_bound(timestamp);
        return it == timeMap[key].begin() ? "" : prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> timeMap {};
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

