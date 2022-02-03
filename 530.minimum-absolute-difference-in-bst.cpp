/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
    // Solution 1: in order traversal
    //  ref: https://zxi.mytechroad.com/blog/tree/leetcode-530-minimum-absolute-difference-in-bst/
    // public:
    //     int getMinimumDifference(TreeNode* root) {
    //         inOrder(root);
    //         return minDiff_;
    //     }
    // private:
    //     int minDiff_ = numeric_limits<int>::max();
    //     TreeNode* prve_ = nullptr;
    //     void inOrder(TreeNode* node){
    //         if(!node){
    //             return;
    //         }
    //         inOrder(node->left);
    //         if(prve_ && minDiff_ > (node->val - prve_->val)){
    //             minDiff_ = node->val - prve_->val;
    //         }
    //         prve_ = node;
    //         inOrder(node->right);
    //     }

    // Solution 2: pre order traversal
    //  explain: use pre order to find diff of each closet nodes pairs
    //  ref: https://www.cnblogs.com/grandyang/p/6540165.html

    // public:
    //     int getMinimumDifference(TreeNode *root)
    //     {
    //         preOrder(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    //         return result_;
    //     }

    // private:
    //     int result_ = numeric_limits<int>::max();

    //     // Parameters:
    //     //  - node: TreeNode*
    //     //  - lower: lower bound of the search, assign previous searched node as 'lower' for right tree
    //     //  - upper: upper bound of the search, assign previous searched node as 'upper' for left tree
    //     void preOrder(TreeNode *node, int lower, int upper)
    //     {
    //         if (!node)
    //         {
    //             return;
    //         }
    //         if (lower != numeric_limits<int>::min())
    //         {
    //             result_ = min(result_, node->val - lower);
    //         }
    //         if (upper != numeric_limits<int>::max())
    //         {
    //             result_ = min(result_, upper - node->val);
    //         }
    //         preOrder(node->left, lower, node->val);
    //         preOrder(node->right, node->val, upper);
    //     }

    // Solution 3: in order traversal (iterative version)
public:
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int result = numeric_limits<int>::max();
        stack<TreeNode *> s;
        TreeNode *head = root;  // used to travel tree
        TreeNode *prev = nullptr;   // used to set the previous node

        while (head || !s.empty())
        {
            // NOTE:
            //  In order traversal travels the left branch to the end first, so it needs to add all left nodes to the stack first
            while (head)
            {
                s.push(head);
                head = head->left;
            }
            head = s.top();
            s.pop();
            if (prev)
            {
                result = min(result, head->val - prev->val);
            }
            prev = head;
            head = head->right;
        }

        return result;
    }
};
// @lc code=end
