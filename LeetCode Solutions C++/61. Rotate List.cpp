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
    
    //METHOD-1
    /*
    naive approach:
    pick last node, put in front and do this k-times
    
    time: 0(k*n), space: O(1)
    */
    
    
    int lengthLL(ListNode *head){
        if(head==NULL) return 0;
        return 1+lengthLL(head->next);
    }
    /*****************/
    //METHOD-2
     //time: O(n), space: O(1)
    ListNode* rotateRight_my_method(ListNode* root, int k) {
        if(root==NULL || root->next==NULL) return root;
        int i=0;
      
        while(i<k % lengthLL(root)){ 
            ListNode *node=root;
            while(node->next->next!=NULL) node=node->next;
            ListNode *tailNode=node->next;
            tailNode->next=root;
            node->next=NULL;
            root=tailNode;
            i++;    
        }
        return root;
    }
    /*****************/
    
    /***************/
    //METHOD-3
     //time: O(n), space: O(1)
    ListNode* rotateRight_striver(ListNode* root, int k){
        if(k == 0 || !root || !root->next)
            return root;
        int len = lengthLL(root);
        k = k % len;
        ListNode *node = root;
        while(node->next){
            node = node->next;
        }
        //attaching node->next to root to make it circualr list
        node->next = root;
        k = len - k;
        node = root;
        while(k > 1){
            node = node->next;
            k--;
        }
        ListNode *newHead = node->next;
        node->next= nullptr;
        return newHead;
    }
    /***************/
    
    ListNode* rotateRight(ListNode* root, int k){
        return rotateRight_striver(root, k);
    }
    
};
