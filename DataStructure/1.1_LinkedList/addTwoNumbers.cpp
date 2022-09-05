// Link: https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ltmp = new ListNode;
        ListNode *lret; lret = ltmp; // get begin iterator
        int rem = 0;
        while (1)
        {
            int L1Val = l1 == nullptr ? 0 : l1->val;
            int L2Val = l2 == nullptr ? 0 : l2->val;
            ltmp->val = ((L1Val + L2Val + rem)%10);
            rem = (int)((L1Val + L2Val + rem)/10);
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            if (l1 == nullptr && l2 == nullptr) break;
            ListNode *lNext = new ListNode;
            ltmp->next = lNext;
            ltmp = lNext;
        }
        if (rem > 0) {
            ListNode *lNext = new ListNode(rem);
            ltmp->next = lNext; 
        }
        return lret;
    }
};