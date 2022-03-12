/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    // Solution 1: Divide and Conqure (use two ptrs)
    //  ref: https://www.cnblogs.com/grandyang/p/10909191.html
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return helper(preorder, 0, (int)preorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
    }

    // Note:
    /* 
    * use two ptrs on each order array, ptrs point the range of tree or subtree, and use first element of 
    * preorder array as the return node
    */
    TreeNode *helper(const vector<int> &preorder, int preL, int preR, const vector<int> &postorder, int postL, int postR)
    {
        if (preL > preR || postL > postR)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[preL]);
        if(preL == preR)
            return node;
        
        // find the corresponding node in the post order array
        int indexInPost;
        for (indexInPost = postL; indexInPost <= postR; ++indexInPost){
            if(preorder[preL + 1] == postorder[indexInPost])
                break;
        }

        // split two arrays to different search range
        node->left = helper(preorder, preL + 1, preL + 1 + (indexInPost - postL), postorder, postL, indexInPost);
        node->right = helper(preorder, preL + 1 + (indexInPost - postL) + 1, preR, postorder, indexInPost + 1, postR - 1);
        return node;
    }

    // Solution 2: using stack
    //  ref: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C%2B%2BJavaPython-One-Pass-Real-O(N)
    //  NOTE: very smart solution
};
// @lc code=end
