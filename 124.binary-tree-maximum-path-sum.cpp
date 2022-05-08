/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    // Solution 1: DFS
    //  ref: http://zxi.mytechroad.com/blog/tree/leetcode-124-binary-tree-maximum-path-sum/
    //  note: same as #543
    int maxPathSum(TreeNode *root)
    {
        result = INT_MIN;
        dfs(root);
        return result;
    }

private:
    int result;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        result = max(result, left + right + root->val);
        return max(left, right) + root->val;
    }
};
// @lc code=end
