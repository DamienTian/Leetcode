/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    // Solution 1
    //  ref: https://zxi.mytechroad.com/blog/tree/leetcode-450-delete-node-in-a-bst/
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else{
            TreeNode* newRoot = nullptr;
            if(root->left == nullptr)   // delete node has no left child
                newRoot = root->right;
            else if(root->right == nullptr) // delete node has no right child
                newRoot = root->left;
            else{
                // find min node in right subtree by traverse left branch
                TreeNode* parent = root;
                newRoot = root->right;
                while(newRoot->left){
                    parent = newRoot;
                    newRoot = newRoot->left;
                }

                if(parent != root){
                    parent->left = newRoot->right;
                    newRoot->right = root->right;
                }
                newRoot->left = root->left;
            }

            delete root;
            return newRoot;
        }

        return root;
    }
};
// @lc code=end
