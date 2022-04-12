/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
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
    // Solution 1: DFS O(n) method
    //  note:       the O(n^2) method check every node to see if it is a valid BST, so the redundant check is not avoidable,
    //note...)      O(n) method only check the tree one time.
    //  ref: https://www.cnblogs.com/grandyang/p/5188938.html
    int largestBSTSubtree(TreeNode *root)
    {
        int result = 0;
        int minVal = INT_MIN, maxVal = INT_MAX;
        checkBST(root, minVal, maxVal, result);
        return result;
    }

private:
    void checkBST(TreeNode *root, int& minVal, int& maxVal, int& result){
        if(!root)
            return;
        // the node count for left and right subtrees
        int resultLeft = 0, resultRight = 0;
        // min and max bounds for left and right subtrees
        int minValLeft = INT_MIN, maxValLeft = INT_MAX;
        int minValRight = INT_MIN, maxValRight = INT_MAX;
        // dfs on both tree
        checkBST(root->left, minValLeft, maxValLeft, resultLeft);
        checkBST(root->right, minValRight, maxValRight, resultRight);
        // if the tree is valid
        if((!root->left || root->val > maxValLeft) && (!root->right || root->val < minValRight)){
            result = resultLeft + resultRight + 1;
            minVal = root->left ? minValLeft : root->val;
            maxVal = root->right ? maxValRight : root->val;
        }
        // if not, update result to be either left count or right count
        else{
            result = max(resultLeft, resultRight);
        }
    }
};

// @lc code=end