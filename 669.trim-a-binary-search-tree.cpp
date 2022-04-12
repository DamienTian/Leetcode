/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
    // Solution: DFS Recursive
    //  ref: http://zxi.mytechroad.com/blog/leetcode/leetcode-669-trim-a-binary-search-tree/
    //  note: this is no garbage collection version, huahua also provide a garbage collection ver, but cannot run on leetcode
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
