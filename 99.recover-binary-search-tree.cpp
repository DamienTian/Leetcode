/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
class Solution
{
public:
    // Solution 1: in order traversal
    //  ref: https://www.cnblogs.com/grandyang/p/4298069.html
    void recoverTree(TreeNode *root)
    {
        inOrder(root);
        swap(first->val, second->val);
    }

private:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void inOrder(TreeNode *root){
        if(!root)
            return;
        inOrder(root->left);
        if(!prev)
            prev = root;
        else{
            if(prev && prev->val > root->val){
                // TODO: figure out why need to have if statement
                if(!first)
                    first = prev;
                second = root;
            }
            prev = root;
        }
        inOrder(root->right);
    }
};
// @lc code=end
