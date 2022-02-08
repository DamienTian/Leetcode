/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
 * 
 * Category: BST, Divide and Conqure
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
    // Solution: In Order Traversal + Divide and Conquer (for building BST)
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        inOrder(root, v);
        return sortedArrayToBST(v);
    }

private:
    // In Order Traversal and store BST in a vector<int>
    void inOrder(TreeNode *root, vector<int>& result){
        if(!root){
            return;
        }
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }

    // Build BST from a sorted vector<int> (copied from my solution of #108)
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
        {
            return new TreeNode();
        }
        return dc(nums, 0, nums.size() - 1);
    }

    TreeNode *dc(const vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return new TreeNode(nums[left]);
        }
        if((right - left) == 1){
            TreeNode* child = new TreeNode(nums[left]);
            TreeNode* head = new TreeNode(nums[right], child, nullptr);
            return head;
        }
        int mid = left + (right - left) / 2;
        TreeNode* leftNode = dc(nums, left, mid - 1);
        TreeNode* rightNode = dc(nums, mid + 1, right);
        TreeNode* midNode = new TreeNode(nums[mid], leftNode, rightNode);
        return midNode;
    }
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

};
// @lc code=end
