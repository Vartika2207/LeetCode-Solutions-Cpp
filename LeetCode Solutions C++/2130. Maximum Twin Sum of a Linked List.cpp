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
    //time: O(3n)
    ListNode *reverseLL(ListNode* head){
        ListNode *prev = NULL, *curr = head;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
    int pairSum_naive(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            if(!fast->next->next)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head1 = head, *temp = slow->next;;
        slow->next = NULL;
        ListNode *head2 = reverseLL(temp);
        
        int maxTwinSum = -1;
        while(head1 and head2){
            int sum = head1->val + head2->val;
            maxTwinSum = max(maxTwinSum, sum);
            head1 = head1->next;
            head2 = head2->next;
        }
        return max(maxTwinSum, 0); 
    }
    
    
public:
    int pairSum(ListNode* head) {
        return pairSum_naive(head);
    }
};
