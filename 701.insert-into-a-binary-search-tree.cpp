/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }
        TreeNode *head = root;
        while (head)
        {
            if (val > head->val)
            {
                if (!head->right)
                {
                    head->right = new TreeNode(val);
                    break;
                }
                else
                {
                    head = head->right;
                }
            }
            else
            {
                if (!head->left)
                {
                    head->left = new TreeNode(val);
                    break;
                }
                else
                {
                    head = head->left;
                }
            }
        }
        return root;
    }
};
// @lc code=end
