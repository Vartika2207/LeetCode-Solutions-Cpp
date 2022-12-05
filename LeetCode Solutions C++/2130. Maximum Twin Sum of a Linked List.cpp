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
    /**********Reverse half linkedlist**************/
    //time: O(3n), space: O(1)
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
    
    int pairSum_reverse(ListNode* head){
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
    /*************************/
    
   /*************************/
    /*************Using stack************/
    //time: O(n), space: o(n/2)
    int pairSum_stack(ListNode* head){
        ListNode *slow = head, *fast = head;
        stack<ListNode*> st;
        
        while(fast and fast->next){
            st.push(slow);
            fast = fast->next->next;
            slow = slow->next;
        }
        
        int maxTwinSum = 0;
        while(!st.empty() and slow){
            int sum = st.top()->val + slow->val;
            maxTwinSum = max(maxTwinSum, sum);
            st.pop();
            slow = slow->next;
        }
        return maxTwinSum; 
    }
    
    /************************/
    
public:
    int pairSum(ListNode* head) {
        return pairSum_stack(head);
    }
};
