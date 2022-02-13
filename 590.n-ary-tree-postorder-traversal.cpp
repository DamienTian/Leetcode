/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    // Solution 1: Recursion (my version)
    // vector<int> postorder(Node *root)
    // {
    //     vector<int> result;
    //     recursion(root, result);
    //     return result;
    // }

    // void recursion(Node *root, vector<int> &result)
    // {
    //     if (!root)
    //     {
    //         return;
    //     }
    //     for (const auto &c : root->children)
    //     {
    //         recursion(c, result);
    //     }
    //     result.push_back(root->val);
    // }

    // Solution 2: Iteration is a reversed preorder traversal
    //  NOTE: could use a stack, then add all childrens nodes into stack first (like a DFS), then the stack is a natural post ordered
    //        ? but I have not come up with a solution 
    vector<int> postorder(Node *root)
    {
        if (!root)
        {
            return {};
        }

        vector<int> result;
        stack<Node*> s;
        s.push(root);

        while(!s.empty()){
            Node* curr = s.top();
            s.pop();
            result.insert(result.begin(), curr->val);
            for(auto c : curr->children){
                s.push(c);
            }
        }
        return result;
    }
    
};
// @lc code=end
