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
    ListNode* reverseListRec(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode *headNext = head->next;
        ListNode *headNew = reverseListRec(headNext);
        (head->next)->next = head; head->next = NULL;
        return headNew;
    }
    
    ListNode* reverseListItr(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode *prev = NULL, *curr = head;
        
        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListItr(head);
    }
};
