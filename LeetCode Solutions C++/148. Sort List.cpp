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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head; 
        ListNode* fast = head;
        ListNode* prev_slow = NULL;
        
        while(fast && fast->next){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_slow->next = NULL;
        return slow;
    }
    
    ListNode* mergeTwoLists_iterative(ListNode* h1, ListNode* h2) {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        
        ListNode* head=NULL,*tail=NULL;
        
        while(h1!=NULL && h2!=NULL){
             if(head==NULL){
                if(h1->val<h2->val){
                    head=h1; tail=h1;
                    h1=h1->next;
                }
                else{
                    head=h2; tail=h2;
                    h2=h2->next;
                }
            }
            else{
                if(h1->val<h2->val){
                    tail->next=h1; tail=h1;
                    h1=h1->next;
                }
                else{
                    tail->next=h2; tail=h2;
                    h2=h2->next;   
                }
            }
        }
        
        if(h2==NULL){
            tail->next=h1;
        }
        if(h1==NULL){
            tail->next=h2;
        }
        return head;
    }
    
    
    ListNode* sortList_helper(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList_helper(head);
        ListNode* right = sortList_helper(mid);
        
        return mergeTwoLists_iterative(left, right);
    }
    
    
    ListNode* sortList(ListNode* head) {
        return sortList_helper(head);
    }
};
