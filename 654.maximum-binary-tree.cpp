/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 * 
 * Category: Divide and Conqure
 */

// @lc code=start
//Definition for a binary tree node.
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
    // Solution 1: Divide and Conquer
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        int maxIndex = maxValIndex(nums);
        TreeNode *node = new TreeNode(nums[maxIndex]);
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        node->left = constructMaximumBinaryTree(leftNums);
        node->right = constructMaximumBinaryTree(rightNums);
        return node;
    }

private:
    // Helper func to find the max val's index in a vector
    //  ref: https://stackoverflow.com/questions/2953491/finding-the-position-of-the-maximum-element
    inline int maxValIndex(vector<int> &nums)
    {
        return distance(nums.begin(), max_element(nums.begin(), nums.end()));
    }

    // Solution 2: Iterative (skip)
    //  ref: https://www.cnblogs.com/grandyang/p/7513099.html
};
// @lc code=end
