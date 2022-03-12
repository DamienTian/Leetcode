/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    // Solution: Two ptrs
    ListNode *middleNode(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        int length = 2;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            length += 2;
        }
        if(!fast)
            --length;
        return (length % 2 == 0) ? slow->next : slow;
    }
};
// @lc code=end
