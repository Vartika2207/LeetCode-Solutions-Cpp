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
    /*****************/
    //time 0(m+n) ; space O(2n)
    ListNode *helper(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        ListNode* ha=headA;
        ListNode* hb=headB;
        while(ha){
            s.insert(ha);
            ha=ha->next;
        }
        while(hb){
            if(s.find(hb)!=s.end())
                return hb;
            else
                hb=hb->next;
        }
        return NULL;
    }
    /*****************/
    
    /*****************/
    //time 0(m + m-n +n) m and are len m>n; space O(1)
    ListNode *helper_using_dummy(ListNode *headA, ListNode *headB) {
        ListNode* dummyA=headA; int lenA=0;
        ListNode* dummyB=headB; int lenB=0;
        while(dummyA){
            lenA++;
            dummyA=dummyA->next;
        }
        while(dummyB){
            lenB++;
            dummyB=dummyB->next;
        }
        int diff=lenA-lenB;
        dummyA=headA;
        dummyB=headB;
        if(diff>0){ //A is bigger
            while(diff--){
                dummyA=dummyA->next;
            }
        }
        if(diff<0){ //B is bigger
            diff=diff*-1;
            while(diff--){
                dummyB=dummyB->next;
            }
        }
        
        while(dummyA && dummyB){
            if(dummyA==dummyB)
                return dummyA;
            dummyA=dummyA->next;
            dummyB=dummyB->next;
        }
        return NULL;
    }
    /*****************/
    
    /*********************/
    //time: 0(l1 + l2), space: O(1)
    ListNode *shortest(ListNode *l1, ListNode *l2){
        if(!l1 || !l2)
            return nullptr;
        
        ListNode *a = l1, *b = l2;
        while(a != b){
            a = a == NULL ? l2 : a->next;
            b = b == NULL ? l1 : b->next;
        }
        return b;
        
    }
    /*********************/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        return shortest(headA, headB);
    }
    
};
