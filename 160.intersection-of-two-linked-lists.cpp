/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// #include "dummyHead.h"
class Solution
{
public:
    // Solution 1: find length, then find intersection
    //  ref: https://www.cnblogs.com/grandyang/p/4128461.html
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     if(!headA || !headB)
    //         return nullptr;
    //     int lenA = getLen(headA), lenB = getLen(headB);
    //     if(lenA > lenB){
    //         for(int i = 0; i < lenA - lenB; ++i)
    //             headA = headA->next;
    //     }
    //     else if(lenA < lenB){
    //         for(int i = 0; i < lenB - lenA; ++i)
    //             headB = headB->next;
    //     }
    //     while(headA && headB && headA != headB){
    //         headA = headA->next;
    //         headB = headB->next;
    //     }
    //     return (headA && headB) ? headA : nullptr;
    // }

    // Solution 2: use thought of 'cycle'
    //  ref: https://www.cnblogs.com/grandyang/p/4128461.html
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA || !headB)
            return nullptr;
        ListNode *a = headA, *b = headB;
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
private:
    int getLen(ListNode *head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
};
// @lc code=end
