/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    // Solution 1: recursion
    //  ref: https://zxi.mytechroad.com/blog/tree/leetcode-98-validate-binary-search-tree/
    // bool isValidBST(TreeNode* root) {
    //     return recursion(root, nullptr, nullptr);
    // }

    // bool recursion(TreeNode* root, const int* min, const int* max){
    //     if(!root){
    //         return true;
    //     }
    //     if((min && root->val <= *min) || (max && root->val >= *max)){
    //         return false;
    //     }
    //     return recursion(root->left, min, &root->val) &&
    //             recursion(root->right, &root->val, max); 
    // }

    // Failed Solution 2: in order travesal of a valid BST should be sorted
    // Why failed: 'prve' is a local static variable, so it cannot be accessed in 'inOrder()' function
    //  ref: https://blog.csdn.net/yangfengby0909/article/details/6501147
    //  note: see the Example Code 1 at the bottom
    // bool isValidBST(TreeNode* root) {
    //     static TreeNode* prve = nullptr;
    //     return inOrder(root, prve);
    // }

    // bool inOrder(TreeNode* root, TreeNode* prve){
    //     if(!root){
    //         return true;
    //     }
    //     if(!inOrder(root->left, prve)){
    //         return false;
    //     }
    //     if(prve && prve->val >= root->val){
    //         return false;
    //     }
    //     prve = root;
    //     return inOrder(root->right, prve);
    // }

    // Solution 2: in order travesal of a valid BST should be sorted
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }

private:
    TreeNode* prve = nullptr;
    bool inOrder(TreeNode* root){
        if(!root){
            return true;
        }
        if(!inOrder(root->left)){
            return false;
        }
        if(prve && prve->val >= root->val){
            return false;
        }
        prve = root;
        return inOrder(root->right);
    }
};


// Example Code 1: access local static variable out-of-scope
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// void s1(){
//     static int* mm; 
//     s2(mm);
// }

// bool s2(int* m){
//     if(!m){
//         *m = 1; // Seg fault, try to access a local static variable 
//         return true;
//     }
//     return false;
// }
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


// @lc code=end

