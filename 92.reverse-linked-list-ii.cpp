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

// note: Take look at #206 for reverse linked list
class Solution
{
public:
    // Solution 1: Mine
    // ListNode *reverseBetween(ListNode *head, int left, int right)
    // {
    //     if(!head || !head->next)
    //         return head;

    //     int numNodesToReverse = right - left;

    //     // Find beginning
    //     ListNode* begin = head;
    //     ListNode* beforeBegin = nullptr;
    //     while(left > 1){
    //         if(left == 2){
    //             beforeBegin = begin;
    //         }
    //         begin = begin->next;
    //         --left;
    //     }

    //     // Reverse
    //     // note:
    //     /*
    //     * The 'begin' will loop out of the range of reverse and end at the index [right - 1]
    //     * so it will be appended to the end for the new list.
    //     * The 'end' is the last element of the reversed list (which is at the begin of the list before reverse)
    //     */
    //     ListNode *end = begin;
    //     ListNode *newHead = nullptr;
    //     while(numNodesToReverse >= 0){
    //         ListNode* temp = begin->next;
    //         begin->next = newHead;
    //         newHead = begin;
    //         begin = temp;
    //         --numNodesToReverse;
    //     }

    //     // Append list
    //     if(!beforeBegin)
    //         head = newHead;
    //     else
    //         beforeBegin->next = newHead;
    //     end->next = begin;

    //     return head;
    // }

    // Solution 2: Grandyang
    //  ref: https://www.cnblogs.com/grandyang/p/4306611.html
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        // prev: the node before reverse range
        ListNode *prev = dummy;
        dummy->next = head;
        for (int i = 0; i < left - 1; ++i)
            prev = prev->next;
        // cursor: the first element of reverse range, will be moved to the back
        ListNode *cursor = prev->next;
        for (int i = left; i < right; ++i)
        {
            ListNode* temp = cursor->next;
            cursor->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};
// @lc code=end
