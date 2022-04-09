/*
 * @lc app=leetcode id=1485 lang=cpp
 *
 * [1485] Clone Binary Tree With Random Pointer
 */

// @lc code=start

// Definition for a Node.
// struct Node
// {
//     int val;
//     Node *left;
//     Node *right;
//     Node *random;
//     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
//     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
//     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
// };
// // pesudo define NodeCopy
// struct NodeCopy
// {
//     int val;
//     NodeCopy *left;
//     NodeCopy *right;
//     NodeCopy *random;
//     NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
//     NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
//     NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
// };
// #include "dummyHead.h"

// note: this problem cannot be test or submit via VS Code Leetcode plugin (not connected yet)

class Solution
{
public:
    // Solution 1: DFS + mem
    NodeCopy *copyRandomBinaryTree(Node *root)
    {
        if (!root)
            return nullptr;
        if (mem.count(root))
            return mem[root];
        NodeCopy *copy = new NodeCopy(root->val);
        mem[root] = copy;

        copy->left = copyRandomBinaryTree(root->left);
        copy->right = copyRandomBinaryTree(root->right);
        copy->random = copyRandomBinaryTree(root->random);

        return copy;
    }

private:
    // store deep copy nodes
    unordered_map<Node *, NodeCopy *> mem;
};

// @lc code=end