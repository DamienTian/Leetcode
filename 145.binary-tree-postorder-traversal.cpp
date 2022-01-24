/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;

    //     function<void(TreeNode*)> helper = [&result, &helper](TreeNode* node){
    //         if(!node){
    //             return;
    //         }
    //         helper(node->left);
    //         helper(node->right);
    //         result.push_back(node->val);
    //     };

    //     helper(root);
    //     return result;
    // }

    // Iterative solution 1 (modified the tree, Not recommend)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if(root){
            s.push(root);
        }
        while(!s.empty()){
            TreeNode* n = s.top();
            if(!n->right && !n->left){
                result.push_back(n->val);
                s.pop();
            }
            if(n->right){
                s.push(n->right); 
                n->right = nullptr;
            }
            if(n->left){ 
                s.push(n->left); 
                n->left = nullptr;    
            }
        }
        return result;
    }

    // Iterative solution 2:
    //  ref: https://zxi.mytechroad.com/blog/tree/leetcode-145-binary-tree-postorder-traversal/
    //  NOTE: Huahua's method techniqully is a preorder traversal but add item reversely.
};
// @lc code=end

