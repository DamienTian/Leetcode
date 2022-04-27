/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: 2d vector + sort 
    // bool isNStraightHand(vector<int> &hand, int groupSize)
    // {
    //     if (hand.size() % groupSize != 0)
    //         return false;
    //     int n = hand.size() / groupSize;
    //     sort(hand.begin(), hand.end());
    //     vector<vector<int>> mem(n);
    //     for (int i = 0; i < hand.size(); ++i)
    //     {
    //         bool canBuild = false;
    //         for (int j = 0; j < mem.size(); ++j)
    //         {
    //             if (mem[j].empty() || (mem[j].size() < groupSize && hand[i] - mem[j].back() == 1))
    //             {
    //                 mem[j].push_back(hand[i]);
    //                 canBuild = true;
    //                 break;
    //             }
    //         }
    //         // printMatrix2DInt(mem);
    //         if (canBuild)
    //             continue;
    //         else
    //             return false;
    //     }
    //     return true;
    // }

    // Solution 2: map
    //  ref: https://www.cnblogs.com/grandyang/p/10468523.html
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // note: this need to be searched from smaller elements to larger elements
        map<int, int> m;
        for (int i : hand) ++m[i];
        for (auto a : m) {
            if (a.second == 0) continue;
            for (int i = a.first + 1; i < a.first + groupSize; ++i) {
                if (m[i] < a.second) return false;
                m[i] = m[i] - a.second;
            }
        }
        return true;
    }
};
// @lc code=end
