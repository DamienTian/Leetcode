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

// ref: https://www.cnblogs.com/grandyang/p/4478820.html
class Solution
{
public:
    // Solution 1: Recursive
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }

    // Solution 2: Iterative
    // ListNode *reverseList(ListNode *head)
    // {
    //     ListNode* newHead = nullptr;
    //     while(head){
    //         ListNode* temp = head->next;
    //         head->next = newHead;
    //         newHead = head;
    //         head = temp;
    //     }
    //     return newHead;
    // }
};
// @lc code=end
