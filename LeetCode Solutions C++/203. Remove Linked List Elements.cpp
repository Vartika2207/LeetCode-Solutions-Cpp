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
    /************************/
    //time O(n), space O(1)
    ListNode* helper(ListNode* head, int val) {
        if(!head) return head;
        
        if(head->val==val){
            return removeElements(head->next, val);
        }
        else{
            head->next=removeElements(head->next, val);
            return head;
        }
        return nullptr;
    }
    /************************/
    
    /************************/
    //time O(n), space O(1)
    ListNode* helper_short(ListNode* head, int val) {
        if(!head) return head;
        
        head->next=removeElements(head->next, val);
        return head->val==val?head->next:head;
            
    }
    /************************/
    
    ListNode* removeElements(ListNode* head, int val){
        return helper_short(head, val);
    }
};
