/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
// #include "dummyHead.h"
// // Definition for a Node.
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


// ref: https://zxi.mytechroad.com/blog/graph/leetcode-133-clone-graph/
//  key: use queue to do search, use map to store the relationship between origin and cloned
//  time: O(# of nodes + # of edges)
//  explain: searched all nodes and edge, since the solution use hashtable to store all searched nodes, no need to search the nodes than has been searched before
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        } 
        // Stores the relationship between original graph and cloned graph
        unordered_map<Node*, Node*> relationship;
        // Nodes have been searched
        set<Node*> searched;
        // Node* to search next (BFS)
        queue<Node*> nextSearch;
        nextSearch.push(node);

        while(!nextSearch.empty()){
            Node* current = nextSearch.front();
            nextSearch.pop();

            if(searched.count(current)){
                continue;
            }
            // Clone the node OR reconstruct exist cloned node
            if(!relationship.count(current)){
                relationship[current] = new Node(current->val);
            }

            // Adding adjancent nodes
            for(auto n : current->neighbors){
                if(!relationship.count(n)){
                    relationship[n] = new Node(n->val);
                }
                relationship[current]->neighbors.push_back(relationship[n]);
                nextSearch.push(n);
            }

            searched.insert(current);
        }

        return relationship[node];
    }
};
// @lc code=end

