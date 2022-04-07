/*
 * @lc app=leetcode id=1062 lang=cpp
 *
 * [1062] Longest Repeating Substring
 */
// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: Binary Search + Hashset
    //  ref: https://leetcode.com/problems/longest-repeating-substring/solution/
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        int l = 1, r = n;
        // loop search half of the string
        //  note: l r m has nothing to do with string index
        while(l <= r){
            int m = l + (r - l) / 2;
            cout << "l = " << l << "    r = " << r << "    m = " << m << endl;
            if(search(s, m) != -1)
                l = m + 1;
            else
                r = m - 1;
        }
        return l - 1;
    }

private:
    // len: stands for search substring length
    int search(string s, int len){
        int n = s.length();
        unordered_set<string> seen;
        for(int i = 0; i < n - len + 1; ++i){
            string curr = s.substr(i, len);
            cout << curr <<endl;
            if(seen.count(curr)){
                cout << curr << " appears twice, it appears second time at index " << i << " with length " << len << endl;
                return i;
            }
            seen.insert(curr);
        }
        cout << "No repeat " << len << " length substring seen" << endl;
        return -1;
    }
};

// @lc code=end