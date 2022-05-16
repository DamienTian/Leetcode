/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// #include "dummyHead.h"

class Solution {
public:
    // Solution: BFS
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        Node* result = new Node(node->val);
        unordered_map<Node*, Node*> records{{node, result}};
        unordered_set<Node*> visited{node};
        queue<Node*> q {{node}};
        while(!q.empty()){
            Node *t = q.front();
            q.pop();

            for(Node* n : t->neighbors){
                if(!records.count(n)){
                    // Node newNode(n->val);
                    records[n] = new Node(n->val);
                }
                records[t]->neighbors.push_back(records[n]);
                if(!visited.count(n)){
                    visited.insert(n);
                    q.push(n);
                }
            }
        }
        return result;
    }
};
// @lc code=end

