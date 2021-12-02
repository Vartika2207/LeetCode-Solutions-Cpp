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
    
    int lengthLL(ListNode* temp){
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
public:
//time: O(n+k), space: O(1)
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k);
        int n = lengthLL(root);
        ListNode* curr = root;
        int size = n/k, extra = n%k;
        
        for(int i=0; i<k; i++){
            ListNode* head = curr;
            
            //fingind tail 
            for(int j=0; j<size+(extra > 0 ? 1: 0)-1; j++){
                if(curr)
                   curr = curr->next;
            }
            if(curr) {//storing tail
                ListNode *prev = curr;
            //making tail as null
            curr = curr->next;
            prev->next = NULL;
           }
            extra -- ;
            ans[i] = head;
        }   
        return ans;
    }
};
