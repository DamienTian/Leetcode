/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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


class Solution
{
    // Solution 1: Recursive
    //  ref: https://grandyang.com/leetcode/445/
    // public:
    //     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    //     {
    //         auto lenOfList = [](ListNode *l)
    //         {
    //             int len = 0;
    //             while (l)
    //             {
    //                 len++;
    //                 l = l->next;
    //             }
    //             return len;
    //         };
    //         int l1Len = lenOfList(l1);
    //         int l2Len = lenOfList(l2);

    //         // Init the result->val = 1 to prevent the most signaficant digit's carry
    //         ListNode *result = new ListNode(1);
    //         result->next = (l1Len > l2Len) ? helper(l1, l2, l1Len - l2Len) : helper(l2, l1, l2Len - l1Len);
    //         if(result->next->val >= 10){
    //             result->next->val %= 10;
    //             return result;
    //         }
    //         return result->next;
    //     }

    //     // diff: Length difference (l1 is longer than l2 in this case)
    //     ListNode* helper(ListNode *l1, ListNode *l2, int diff){
    //         // Base case
    //         if(!l1){
    //             return nullptr;
    //         }
    //         // Calculate each digits from the most signaficant digit to the end WITHOUT carry
    //         ListNode* current = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
    //         // Recursively calculate the carry from the next node
    //         ListNode* next = (diff == 0) ? helper(l1->next, l2->next, diff) : helper(l1->next, l2, diff - 1);

    //         if(next && next->val >= 10){
    //             current->val += (next->val / 10);
    //             next->val %= 10;
    //         }

    //         current->next = next;
    //         return current;
    //     }

    // Solution 2: Iterative 
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(1);
        stack<ListNode *> s;
        int ll1 = lenOfList(l1);
        int ll2 = lenOfList(l2);
        while (l1 || l2)
        {
            int n1 = (ll1 >= ll2) ? l1->val : 0;
            int n2 = (ll2 >= ll1) ? l2->val : 0;
            if (ll1 > ll2)
            {
                --ll1;
                l1 = l1->next;
            }
            else if (ll1 < ll2)
            {
                --ll2;
                l2 = l2->next;
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }

            ListNode *newBuild = new ListNode(n1 + n2);
            s.push(newBuild);
        }

        int carry = 0;
        while (!s.empty())
        {
            ListNode *current = s.top();
            s.pop();
            current->val += carry;
            if (current->val >= 10)
            {
                carry = current->val / 10;
                current->val %= 10;
            }
            else{
                carry = 0;
            }
            current->next = result->next;
            result->next = current;
        }
        if (carry > 0)
        {
            return result;
        }
        return result->next;
    }

private:
    int lenOfList(ListNode *l)
    {
        int len = 0;
        while (l)
        {
            len++;
            l = l->next;
        }
        return len;
    };
};
// @lc code=end
