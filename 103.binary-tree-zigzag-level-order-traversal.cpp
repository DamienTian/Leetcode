/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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

// Review: 1

class Solution
{
public:
    // Solution 1: BFS iteration
    //  ref: https://www.cnblogs.com/grandyang/p/4297009.html
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q{{root}};
        vector<vector<int>> result;
        // zigzag direction
        bool toRight = true;
        while (!q.empty())
        {   
            // allocate the space of a level
            int size = q.size();
            vector<int> currentLevel(size);
            for (int i = 0; i < size; ++i)
            {
                TreeNode *t = q.front(); 
                q.pop();
                // calculate index of insert position base on travel direction
                int index = toRight ? i : size - 1 - i;
                currentLevel[index] = t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            toRight = !toRight;
            result.push_back(currentLevel);
        }
        return result;
    }

    // TODO: Solution 2: BFS iterative 
    //  note: follow the same pattern of #102 solution 2
};
// @lc code=end
