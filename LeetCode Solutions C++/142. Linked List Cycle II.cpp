/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        
        ListNode *slow = head, *fast = head, *ans = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != ans){
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
        }
          return nullptr;
    }
};
