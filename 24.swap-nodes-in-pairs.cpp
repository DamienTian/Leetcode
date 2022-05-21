/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    // Solution 1: iteration
    //  ref: https://www.cnblogs.com/grandyang/p/4441680.html
    // ListNode *swapPairs(ListNode *head)
    // {
    //     ListNode dummy(-1);
    //     dummy.next = head;
    //     ListNode *node = &dummy;
    //     while (node->next && node->next->next)
    //     {
    //         ListNode *t = node->next->next;
    //         node->next->next = t->next;
    //         t->next = node->next;
    //         node->next = t;
    //         node = t->next;
    //     }
    //     return dummy.next;
    // }

    // Solution 2: Backtrace recursion
    //  ref: https://www.cnblogs.com/grandyang/p/4441680.html
    ListNode *swapPairs(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        ListNode* t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
};
// @lc code=end
