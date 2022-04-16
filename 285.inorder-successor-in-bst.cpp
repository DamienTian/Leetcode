/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 */

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: in order with O(n) space 
    // TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    // {
    //     vector<TreeNode*> inordered;
    //     inorderStoreVector(root, p, inordered);
    //     return (targetIndex == inordered.size() - 1) ? nullptr : inordered[targetIndex + 1];
    // }

    // Solution 2: in order with O(1) space 
    //  ref: https://www.cnblogs.com/grandyang/p/5306162.html
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!p) return nullptr;
        inorder(root, p);
        return successor;
    }

private:
    // in order traversal with a vector to store results
    int targetIndex = -1;
    void inorderStoreVector(TreeNode *root, TreeNode *p, vector<TreeNode*>& inordered){
        if(!root)
            return;
        inorderStoreVector(root->left, p, inordered);
        inordered.push_back(root);
        if(root == p)
            targetIndex = inordered.size() - 1;
        inorderStoreVector(root->right, p, inordered);
    }

    // in order traversal with two pointers to store results
    TreeNode *previous = nullptr, *successor = nullptr;
    void inorder(TreeNode *root, TreeNode *p){
        if(!root)
            return;
        inorder(root->left, p);
        if(previous == p){
            //cout << root->val <<endl;
            successor = root;
            //return;   // do not return here! Previous will stop update if return,
                        // and all the successor will has previous becomes the leftest node
        }
        previous = root;
        inorder(root->right, p);
    }
};

// @lc code=end
