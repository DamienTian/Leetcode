/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
class Solution {
public:
    // Recursive solution
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
        
    //     function<void(TreeNode*)> helper = [&result, &helper](TreeNode* n){
    //         if(!n){ return; }
    //         helper(n->left);
    //         result.push_back(n->val);
    //         helper(n->right);
    //     };

    //     helper(root);
    //     return result;
    // }

    // Iterative solution
    //  ref: https://www.cnblogs.com/grandyang/p/4297300.html (solution 2)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            // keep pushing left node into stack
            while(root){
                s.push(root);
                root = root->left;
            }
            // when reach the end of left branch, add val to result and move to it's right branch
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }

        return result;
    }
};
// @lc code=end

