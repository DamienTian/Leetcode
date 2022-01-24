/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// IDEA: follows same logic as Problem #133
// NOTE: if the space need to be O(1), ref: https://www.cnblogs.com/grandyang/p/4261431.html (last solution) 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        // Records the corresponding relationship between original and clone lists
        unordered_map<Node*, Node*> mem;

        // Loop first time to build cloned nodes
        Node* it = head;
        while(it){
            mem[it] = new Node(it->val);
            it = it->next;
        }

        // Loop again to connect list
        it = head;
        while(it){
            mem[it]->next = mem[it->next];
            if(it->random){
                mem[it]->random = mem[it->random];
            }
            it = it->next;
        }

        return mem[head];
    }
};
// @lc code=end

