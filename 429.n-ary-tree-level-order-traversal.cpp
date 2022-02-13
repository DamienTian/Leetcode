/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
// Definition for a Node.
// class Node
// {
// public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val)
//     {
//         val = _val;
//     }

//     Node(int _val, vector<Node *> _children)
//     {
//         val = _val;
//         children = _children;
//     }
// };

class Solution
{
public:
    // Solution 1: Iterative (my version)
    //  TODO: too complicated, refer to huahua to see how to make it simple
    // vector<vector<int>> levelOrder(Node *root)
    // {
    //     if (!root)
    //     {
    //         return {};
    //     }

    //     vector<vector<int>> result{};
    //     vector<int> level{};
    //     queue<Node *> q;
    //     q.push(root);
    //     int currentNumLevel = 1;
    //     int nextNumLevel = 0;

    //     while (!q.empty() || !level.empty())
    //     {
    //         if (currentNumLevel == 0)
    //         {
    //             result.push_back(level);
    //             level.clear();
    //             currentNumLevel = nextNumLevel;
    //             nextNumLevel = 0;
    //         }
    //         else if (currentNumLevel > 0)
    //         {
    //             Node *current = q.front();
    //             q.pop();
    //             level.push_back(current->val);
    //             for (auto c : current->children)
    //             {
    //                 q.push(c);
    //                 ++nextNumLevel;
    //             }

    //             --currentNumLevel;
    //         }
    //     }

    //     return result;
    // }

    // Solution 2: Recursive (my version)
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result {};
        recursion(root, result, 0);
        return result;
    }

    void recursion(Node *root, vector<vector<int>> &result, int level)
    {
        if (!root)
        {
            return;
        }
        if(level >= result.size()){
            result.push_back({});
        }
        result[level].push_back(root->val);
        for(auto c : root->children){
            recursion(c, result, level + 1);
        }
    }
};
// @lc code=end
