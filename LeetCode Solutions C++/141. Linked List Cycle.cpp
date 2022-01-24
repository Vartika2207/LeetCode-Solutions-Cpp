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
    //Method 1: use a hash table time: 0(n), space: O(n)
    
    //method 2: using tortoise method, time O(n), space(1)
    bool better(ListNode *head){
        if(!head || !head->next)
            return false;
        
        ListNode *fast = head, *slow = head;
        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        return better(head);
    }
    
};
