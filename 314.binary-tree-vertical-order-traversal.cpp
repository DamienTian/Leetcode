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
        // return longVersionBFS(root);
        return grandyangBFS(root);
    }

private:
    //  ref: https://www.cnblogs.com/grandyang/p/5278930.html
    vector<vector<int>> grandyangBFS(TreeNode *root)
    {
        if(!root)
            return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            auto nodePair = q.front();
            TreeNode* node = nodePair.first;
            int col = nodePair.second;
            q.pop();
            m[col].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left, col - 1));
            if(node->right)
                q.push(make_pair(node->right, col + 1));
        }
        vector<vector<int>> result;
        for(auto mm : m){
            result.push_back(mm.second);
        }
        return result;
    }

    vector<vector<int>> longVersionBFS(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> result;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        int leftBound = 0, rightBound = 0;

        while (!q.empty())
        {
            auto currentNode = q.front();
            q.pop();
            // Find the correct column and insert
            if (result.empty() || currentNode.second > rightBound)
            {
                result.push_back({currentNode.first->val});
                rightBound = currentNode.second;
            }
            else if (currentNode.second < leftBound)
            {
                result.insert(result.begin(), {currentNode.first->val});
                leftBound = currentNode.second;
            }
            else
            {
                int currentSize = rightBound - leftBound + 1;
                int index = currentNode.second < 0 ? -(leftBound - currentNode.second) : currentSize - (rightBound - currentNode.second) - 1;
                result[index].push_back(currentNode.first->val);
            }
            // Push into queue
            if (currentNode.first->left)
                q.push(make_pair(currentNode.first->left, currentNode.second - 1));
            if (currentNode.first->right)
                q.push(make_pair(currentNode.first->right, currentNode.second + 1));
        }
        return result;
    }
};

// @lc code=end
