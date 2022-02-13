/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    // vector<int> preorder(Node *root)
    // {
    //     if (!root)
    //     {
    //         return {};
    //     }

    //     vector<int> result;
    //     stack<Node*> s;
    //     s.push(root);

    //     while(!s.empty()){
    //         Node* curr = s.top();
    //         s.pop();
    //         result.push_back(curr->val);
    //         for(int i = curr->children.size() - 1; i >= 0; --i){
    //             s.push(curr->children[i]);
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: Recursion (my version)
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        recursion(root, result);
        return result;
    }

    void recursion(Node* root, vector<int>& result){
        if(!root){
            return;
        }
        result.push_back(root->val);
        for(const auto& c : root->children){
            recursion(c, result);
        }
    }
};
// @lc code=end
