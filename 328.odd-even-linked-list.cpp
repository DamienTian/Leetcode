/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    // Solution 1: Single ptr with dummy node store (mine)
    // ListNode *oddEvenList(ListNode *head)
    // {
    //     if (!head || !head->next)
    //     {
    //         return head;
    //     }
    //     ListNode dummyEven(-1);
    //     ListNode *dummyCursor = &dummyEven;
    //     ListNode *cursor = head;
    //     while (cursor && cursor->next)
    //     {
    //         ListNode *even = cursor->next;
    //         dummyCursor->next = even;
    //         cursor->next = cursor->next->next;
    //         even->next = nullptr;
    //         if (!cursor->next)
    //             break;
    //         cursor = cursor->next;
    //         dummyCursor = dummyCursor->next;
    //     }

    //     cursor->next = dummyEven.next;
    //     return head;
    // }

    // Solution 2: Two ptrs (Grandyang)
    //  ref: https://www.cnblogs.com/grandyang/p/5138936.html
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *odd = head, *even = head->next, *even_head = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
// @lc code=end
