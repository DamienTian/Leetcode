/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// #include "dummyHead.h"

// Solution: BFS (Iteration) + Two Pointers (in deserialize())
//  note: take look at grandyang's recursion version: https://www.cnblogs.com/grandyang/p/4913869.html
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string result = "";
        queue<TreeNode *> q{{root}};
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            bool nextLevelAllNull = true;
            string currentLevel = "";

            // serialize by each level
            for (int i = 0; i < currentLevelSize; ++i)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                currentLevel += currentNode ? to_string(currentNode->val) + "," : "null,";
                if (!currentNode)
                    continue;
                else if (currentNode->left || currentNode->right)
                    nextLevelAllNull = false;
                
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
            result += currentLevel;
            if (nextLevelAllNull)
                break;
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        // vector to store TreeNode*, it will order like data
        vector<TreeNode *> result(data.length());
        size_t found = data.find_first_of(",");

        // using two pair of pointers (indices) to do the search
        int currentLevelStart = 0, currentLevelEnd = 1;
        int previousLevelStart = -1, previousLevelEnd = -1;
        int nextLevelCount = 0;

        while (found != std::string::npos)
        {
            // Read data and put tree node into vector
            for (int i = currentLevelStart; i < currentLevelEnd; ++i)
            {
                string nodeString = data.substr(0, found);
                data = data.substr(found + 1, data.length() - nodeString.length());
                if (nodeString != "null")
                {
                    result[i] = new TreeNode(stoi(nodeString));
                    nextLevelCount += 2;
                }
                else
                {
                    result[i] = nullptr;
                }
                found = data.find_first_of(",");
            }

            // Link the tree
            if (previousLevelStart != -1 && previousLevelEnd != -1)
            {
                for (int i = previousLevelStart, j = currentLevelStart + 1; i < previousLevelEnd, j < currentLevelEnd; ++i, j += 2)
                {
                    if(result[i]){
                        result[i]->left = result[j - 1];
                        result[i]->right = result[j];
                    }
                    else{
                        j -= 2;
                    }
                }
            }

            // reset the searching indices
            previousLevelStart = currentLevelStart;
            previousLevelEnd = currentLevelEnd;
            currentLevelStart = currentLevelEnd;
            currentLevelEnd = currentLevelStart + nextLevelCount;
            nextLevelCount = 0;
        }

        return result[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
