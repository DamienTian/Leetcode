/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// Solution: Divide and conquer
//  ref: https://www.cnblogs.com/grandyang/p/4296500.html
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    // pLeft & pRight: search range indices of preorder 
    // iLeft & iRight: search range indices of inorder
    TreeNode* buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight){
        if(pLeft > pRight || iLeft > iRight)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[pLeft]);
        if(pLeft == pRight)
            return node;
        
        // find the root index in the inorder
        int i = iLeft;
        while(i <= iRight){
            if(preorder[pLeft] == inorder[i])
                break;
            i++;
        }
        // construct the left and right node
        node->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        node->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return node;
    }
};
// @lc code=end
