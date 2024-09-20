/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
// #include "../dummyHead.h"

// Solution: Stack (treat vector as stack)
//  ref: https://www.cnblogs.com/grandyang/p/4347125.html
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string result, current;
        vector<string> dirs;
        while (getline(ss, current, '/')) {
            if(current == "." || current == "") 
                continue;
            if(current == ".." && !dirs.empty()){
                dirs.pop_back();
            }
            else if(current != "..")
                dirs.push_back(current);
        }
        for(auto d: dirs){
            result += "/" + d;
        }
        return result.empty() ? "/" : result;
    }
};
// @lc code=end

