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
    // app1: iterative running on loops => time: O(n+m)
    ListNode* addTwoNumbers_naive(ListNode* l1, ListNode* l2) {
        if(l1 == NULL or l2 == NULL)
            return l1 == NULL ? l2 : l1;
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int carry = 0;
        while(l1 != NULL and l2 != NULL) {
            int sum = (l1->val + l2->val + carry);
            carry = sum / 10;
            sum = sum % 10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            int sum = (l1->val + carry);
            carry = sum / 10;
            sum = sum % 10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int sum = (l2->val + carry);
            carry = sum / 10;
            sum = sum % 10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
            l2 = l2->next;
        }
        if(carry != 0) {
            dummy->next = new ListNode(carry);
            dummy = dummy->next;
        }
        return head->next;
    }

    ListNode* addTwoNumbers_rec(ListNode* l1, ListNode* l2) {
        if(l1 == NULL or l2 == NULL)
            return l1 == NULL ? l2 : l1;

        int sum = (l1->val + l2->val);
        int carry = sum / 10;
        sum = sum % 10;
        ListNode *head = new ListNode(sum);
        
        head->next = addTwoNumbers_rec(l1->next, l2->next);
        if(carry > 0)
            head->next = addTwoNumbers_rec(head->next, new ListNode(1));
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers_rec(l1, l2);
    }
};
