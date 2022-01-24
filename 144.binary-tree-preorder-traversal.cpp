/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;

    //     // NOTE: a recursive lambda need to capture itself in capture list
    //     function<void(TreeNode*)> helper = [&result, &helper](TreeNode* node){
    //         if(!node){
    //             return;
    //         }
    //         result.push_back(node->val);
    //         helper(node->left);
    //         helper(node->right);
    //     };

    //     helper(root);
    //     return result;
    // }

    // Iterative solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root){
            s.push(root);
        }
        while(!s.empty()){
            TreeNode* node = s.top();
            result.push_back(node->val);
            s.pop();
            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }
        }

        return result;
    }
};
// @lc code=end

