/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    // Solution 1: in Order With extra space (use hash table)
    // vector<int> findMode(TreeNode *root)
    // {
    //     if (!root)
    //         return {};
    //     inOrder(root);
    //     vector<int> result;
    //     for (const auto& r : record)
    //     {
    //         if (r.second == modeAccont)
    //             result.push_back(r.first);
    //     }
    //     return result;
    // }

    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (!record.count(root->val))
            record[root->val] = 0;
        record[root->val] += 1;
        modeAccont = max(modeAccont, record[root->val]);
        inOrder(root->right);
    }

    // Solution 2: InOrder iterative without extra space
    //  ref: https://www.cnblogs.com/grandyang/p/6436150.html
    vector<int> findMode(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> result;
        TreeNode *head = root;
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        int maxCount = 0, currentCount = 1;
        while (head || !s.empty())
        {
            while (head)
            {
                s.push(head);
                head = head->left;
            }
            head = s.top();
            s.pop();
            if (prev)
            {
                // note: using the property of inorder traversal --- elements are in order
                currentCount = (head->val == prev->val) ? currentCount + 1 : 1;
            }
            if (currentCount >= maxCount)
            {
                if (currentCount > maxCount)
                    result.clear();
                result.push_back(head->val);
                maxCount = currentCount;
            }
            prev = head;
            head = head->right;
        }

        return result;
    }

private:
    unordered_map<int, int> record;
    int modeAccont = 0;
};
// @lc code=end
