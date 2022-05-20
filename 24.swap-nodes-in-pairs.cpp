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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *node = dummy.next;
        while (node && node->next)
        {
            ListNode *newHead = node->next;
            ListNode *newTail = node;
            ListNode *temp = newHead->next;
            newHead->next = newTail;
            newTail->next = temp;
            node = newTail->next;
        }
        return dummy.next;
    }
};
// @lc code=end
