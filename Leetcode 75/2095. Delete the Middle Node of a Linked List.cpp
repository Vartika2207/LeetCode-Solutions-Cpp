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
    //Approach-1: find mid and delete
    
    //Approach-2 fast and slow ->time: O(n); space: O(1)
    ListNode* deleteMiddle_tortoise(ListNode* head) {
        if(!head or !head->next)
            return !head?NULL:head->next=NULL;
        
        ListNode *slow = head, *fast = head->next->next; //fast is ahead bcz we need prev of slow
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        toDelete->next = NULL; delete toDelete;
        
        return head;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        return deleteMiddle_tortoise(head);
    }
};
