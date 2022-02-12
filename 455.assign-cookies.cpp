/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   // Sort is O(nlog(n))
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        return i;
    }
};
// @lc code=end

