/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    // Solution 1: BFS (iteration)
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        vector<int> currentLevel;
        // Use two queue to store node, q1 for current level, q2 for next level
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while (!q1.empty() || !q2.empty())
        {
            TreeNode *currentNode = q1.front();
            q1.pop();
            currentLevel.push_back(currentNode->val);
            if (currentNode->left)
                q2.push(currentNode->left);
            if (currentNode->right)
                q2.push(currentNode->right);
            if (q1.empty())
            {
                result.push_back(currentLevel);
                currentLevel.clear();
                swap(q1, q2);
            }
        }

        return result;
    }

    // Solution 2: BFS (recursion)
    //  ref: https://www.cnblogs.com/grandyang/p/4051321.html
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     vector<vector<int>> result;
    //     levelOrder(root, 0, result);
    //     return result;
    // }

private:
    void levelOrder(TreeNode *root, int level, vector<vector<int>> &result)
    {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back({});
        result[level].push_back(root->val);
        if (root->left)
            levelOrder(root->left, level + 1, result);
        if (root->right)
            levelOrder(root->right, level + 1, result);
    }
};
// @lc code=end
