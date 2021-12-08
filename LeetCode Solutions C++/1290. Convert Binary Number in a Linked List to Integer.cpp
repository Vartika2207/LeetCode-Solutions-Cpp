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
    
    /***********Approach-1***************/
    int getDecimalValueRec(ListNode *head){
        static int power = 0;
        if(!head) 
            return 0;
        return getDecimalValueRec(head->next) + head->val << power;
    }
    /**************************/
    
    /************Approach-2**************/
    int getDecimalValueItr(ListNode* head) {
        if(!head)
            return 0;
        int answer = head->val;
       
        while(head->next){
            answer = answer*2 + head->next->val ;
            head = head->next;
        }
        return answer;
    }
    /**************************/
public:
    int getDecimalValue(ListNode *head){
        return getDecimalValueItr(head);
    }
};
