/*
 * @lc app=leetcode id=444 lang=cpp
 *
 * [444]  Sequence Reconstruction
 */

// @lc code=start
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/6032498.html
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        if(sequences.empty())
            return false;
        int n = nums.size();
        // count # of elements to be verified 
        //  (no need to verify the first element of the supersequence nums, so n - 1)
        int count = n - 1; 
        // position of element inside nums
        vector<int> pos(n + 1);
        for(int i = 0; i < n; ++i)
            pos[nums[i]] = i;
        // records each element in nums has be verified in right ordered with it's previous order
        //  note: need to be strictly true, then the sequences has only 1 supersequence
        vector<bool> flags(n + 1, false);
    
        for(auto& s : sequences){
            for(int i = 0; i < s.size(); ++i){
                if(s[i] <= 0 || s[i] > n)
                    return false;
                if(i > 0){
                    int pre = s[i - 1];
                    int cur = s[i];
                    if(pos[pre] >= pos[cur])
                        return false;
                    // if cur is behind the pre
                    if(!flags[cur] && pos[pre] + 1 == pos[cur]){
                        flags[cur] = true;
                        count--;
                    }
                }
            }
        }
        return count == 0;
    }
};

// @lc code=end