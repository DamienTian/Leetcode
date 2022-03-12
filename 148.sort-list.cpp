/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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

// Solution: merge sort
//  ref: https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-148-sort-list/
class Solution
{
public:
    // Solution 1: recursion (space O(logn))
    // ListNode *sortList(ListNode *head)
    // {
    //     if(!head || !head->next)
    //         return head;
    //     // Use two ptrs to split list
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;
    //     //cout << "slow = " << slow->val << " fast = " << fast->val << endl;
    //     while(fast && fast->next){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //         //cout << "slow = " << slow->val << " fast = " << fast->val << endl;
    //     }
    //     ListNode* mid = slow->next;
    //     slow->next = nullptr;
    //     //cout << "make a split at mid = " << mid->val << endl;
    //     return merge1(sortList(head), sortList(mid));
    // }

    // Solution 2: iteration (space O(1))
    ListNode *sortList(ListNode *head)
    {
        if(!head || !head->next)
            return head;

        // find the len of list
        int len = 1;
        ListNode* current = head;
        while(current = current->next)
            ++len;
        ListNode dummy(0);
        dummy.next = head;

        // l: left part
        // r: right part
        // tail: cursor of dummy to build the list 
        ListNode *l, *r, *tail;

        // using merge sort algorithm to split list into
        for(int n = 1; n < len; n *= 2){
            current = dummy.next;
            tail = &dummy;
            // split the list
            while(current){
                l = current;
                r = split(l, n);
                current = split(r, n);
                auto merged = merge2(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }

private:
    // Merge function for Solution 1
    ListNode* merge1(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // Split list into two part for Solution 2
    //  Two parts: first n elements & the rest
    //  Return the head of the rest.
    ListNode* split(ListNode* head, int n){
        while(--n && head)
            head = head->next;
        ListNode* rest = head ? head->next : nullptr;
        if(head)
            head->next = nullptr;
        return rest;
    }

    // Merge function for Solution 2
    //  this returns the head and tail of merged list
    pair<ListNode*, ListNode*> merge2(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next)
            tail = tail->next;
        return {dummy.next, tail};
    }
};
// @lc code=end
