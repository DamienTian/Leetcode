/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// #include "dummyHead.h"

// TODO: This Problem can also be solved by Divide and Conquer

class Solution
{
public:
    // Solution 1: Min heap
    //  ref (currect my code details): https://www.cnblogs.com/grandyang/p/5454125.html
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        function<bool(ListNode*, ListNode*)> compare = [](ListNode* n1, ListNode *n2){
            return n1->val > n2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(compare);
        for(ListNode* list : lists){
            // Wrong way:
            //  if push every listnode into heap, each node has it's next remain behind it
            //  so when construct the answer will cause stack overflow, because all ListNode*
            //  are not deleted right.
            //  note: run [[-1,-1,-1],[-2,-2,-1]] to see the error
            // while(list){
            //     pq.push(list);
            //     list = list->next;
            // }
            
            // Right way:
            //  push all List head into min heap
            if(list)
                pq.push(list);
        }

        ListNode result(-1) , *head = &result;
        while(!pq.empty()){
            head->next = pq.top();
            pq.pop();
            head = head->next;
            
            // Add these code to make it right:
            //  Push the next List head into min heap
            if(head->next)
                pq.push(head->next);
        }
        return result.next;
    }
};
// @lc code=end
