/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    // Solution
    //  ref: https://www.cnblogs.com/grandyang/p/4306611.html
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy(-1);
        dummy.next = head;
        // note: preHead will be moved to the end of the linked list 
        ListNode *pre = &dummy, *preHead = nullptr;
        for(int i = 1; i < left; ++i)
            pre = pre->next;
        preHead = pre->next;
        for(int i = left; i < right; ++i){
            ListNode* t = preHead->next;
            preHead->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy.next;
    }
};
// @lc code=end
