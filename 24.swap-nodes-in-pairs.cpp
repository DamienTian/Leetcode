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
    // Solution 1: Iterative
    // ListNode *swapPairs(ListNode *head)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return head;

    //     // Use a dummy node to return result
    //     ListNode *root = new ListNode(-1);
    //     ListNode* result = root;

    //     while (head && head->next)
    //     {
    //         ListNode *oldNext = head->next;
    //         head->next = oldNext->next;
    //         oldNext->next = head;
    //         root->next = oldNext;
    //         head = head->next;
    //         root = root->next->next;
    //     }
    //     return result->next;
    // }

    // Solution 2: Recursive
    //  ref: https://www.cnblogs.com/grandyang/p/4441680.html
    ListNode *swapPairs(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};
// @lc code=end
