/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy, *oldHead = pre->next;
        while(oldHead->next){
            ListNode* t = oldHead->next;
            oldHead->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy.next;
    }
};
// @lc code=end
