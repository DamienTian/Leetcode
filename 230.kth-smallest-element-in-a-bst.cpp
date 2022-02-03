/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode *root, int k)
    {
        index_ = k;
        return kthSmallestInOrder(root, k);
    }

private:
    int index_;
    int kthSmallestInOrder(TreeNode *root, int &k)
    {
        // base case
        if (!root)
            return -1;

        // search in left subtree
        int left = kthSmallestInOrder(root->left, k);

        // if k'th smallest is found in left subtree, return it
        if (left != -1)
            return left;

        // if current element is k'th smallest, return it
        k--;
        if (k == 0)
            return root->val;

        // else search in right subtree
        return kthSmallestInOrder(root->right, k);
    }
};

// @lc code=end
