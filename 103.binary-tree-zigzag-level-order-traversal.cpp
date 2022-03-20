/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
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

class Solution {
public:
    // Solution 1: BFS (Iteration)
    //  note: take look at grandyang's solution 2 - https://www.cnblogs.com/grandyang/p/4297009.html (similar, but it allocates space first, and put at correct index)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q {{root}};
        while(!q.empty()){
            vector<int> currentLevel;
            int currentLevelSize = q.size();

            // use a stack to store right order
            stack<TreeNode*> s;

            for(int i = 0; i < currentLevelSize; ++i){
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                // make next level zigzag shape depends on the current search level
                if(result.size() % 2 == 0){
                    if(currentNode->left) s.push(currentNode->left);
                    if(currentNode->right) s.push(currentNode->right);
                }
                else{
                    if(currentNode->right) s.push(currentNode->right);
                    if(currentNode->left) s.push(currentNode->left);
                }
            }

            // push back to queue in right searching order
            if(q.empty() && !s.empty()){
                while(!s.empty()){
                    q.push(s.top());
                    s.pop();
                }
            }
            
            result.push_back(currentLevel);
        }

        return result;
    }
};

// [0,2,4,1,null,3,-1,5,1,null,6,null,8]
// @lc code=end

