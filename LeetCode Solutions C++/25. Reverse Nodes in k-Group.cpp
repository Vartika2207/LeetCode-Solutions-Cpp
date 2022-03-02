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
 //time: O(n), space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* node = head->next;
        head->next = NULL;
        
        ListNode* tail = node;
        ListNode* reversed_node = reverseList(node);
        tail->next = head;
        return reversed_node;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1)
            return head;
        
        int count = 0;
        ListNode* curr = head;
        while(curr){
                curr = curr->next;
                count++;
            }
        
        if(count < k)
            return head;
        
        curr = head;
        for(int i=1; i< k; i++){
            curr = curr->next;
        }
        ListNode* curr_next = curr->next;
        curr->next = NULL;
        ListNode* temp_head = head;
        ListNode* k_reversed_node = reverseList(head);
        temp_head->next = reverseKGroup(curr_next, k);
        
        return k_reversed_node;
        
    }
};
