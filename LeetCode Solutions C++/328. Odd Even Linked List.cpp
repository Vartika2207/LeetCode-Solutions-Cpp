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
    //time: O(n), space: O(1)
    ListNode* oddEvenList_naive(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode *odd = head, *even = head->next, *even_temp = even;
        while(odd and even and even->next){
            odd->next = even->next;
            odd = odd->next;
            if(!odd)
                break;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_temp;
        return head;    
    }
    
    ListNode* oddEvenList(ListNode* head){
        return oddEvenList_naive(head);
    }
};
