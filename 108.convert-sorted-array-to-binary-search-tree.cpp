/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * Category: Divide and Conqure
 */

// @lc code=start
// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Divide and Conquer
    //  note: Check Grandyang's version, it is cleaner becasue it has less base check in recursion
    //  ref: this is grandyang's version: https://www.cnblogs.com/grandyang/p/4295245.html
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;
        int mid = nums.size() / 2;
        TreeNode *result = new TreeNode(nums[mid]);
        vector<int> leftSub(nums.begin(), nums.begin() + mid);
        vector<int> rightSub(nums.begin() + mid + 1, nums.end());
        result->left = sortedArrayToBST(leftSub);
        result->right = sortedArrayToBST(rightSub);
        return result;
    }
};
// @lc code=end
