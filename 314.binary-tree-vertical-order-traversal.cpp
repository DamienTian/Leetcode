/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
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
    // Solution: BFS
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        if(!root)
            return {};

        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int leftBound = 0, rightBound = 0;

        while(!q.empty()){
            auto currentNode = q.front();
            q.pop();

            // Find the right column and insert
            if(result.empty() || currentNode.second > rightBound){
                result.push_back({currentNode.first->val});
                rightBound = currentNode.second;
            }
            else if(currentNode.second < leftBound){
                result.insert(result.begin(), {currentNode.first->val});
                leftBound = currentNode.second;
            }
            else{
                int currentSize = rightBound - leftBound + 1;
                int index = currentNode.second < 0 ? -(leftBound - currentNode.second) : currentSize - (rightBound - currentNode.second) - 1;
                result[index].push_back(currentNode.first->val);
            }
                
            // Push into queue
            if(currentNode.first->left)
                q.push(make_pair(currentNode.first->left, currentNode.second - 1));
            if(currentNode.first->right)
                q.push(make_pair(currentNode.first->right, currentNode.second + 1));
        }

        return result;
    }
};

// @lc code=end
