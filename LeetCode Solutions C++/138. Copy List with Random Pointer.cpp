/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    //time: O(n), space: O(1)
    Node* copyRandom_helper(Node *head){
        Node *itr = head;
        Node *front = head;
        
        //step-1
        while(itr){
            front = itr->next;
            
            Node* copy_node = new Node(itr->val);
            itr->next = copy_node;
            copy_node->next = front;
            itr = front;
        }
        
        //step-2
        itr = head;
        while(itr){
            if(itr->random)
               itr->next->random = itr->random->next;
            
            itr = itr->next->next;
        }
        
        //step-3
        itr = head;
        Node* dummy = new Node(0);
        Node* copied_node = dummy;
        while(itr){
            front = itr->next->next;
            dummy->next = itr->next;
            itr->next = front;
            dummy = dummy->next;
            itr = itr->next;
        }
        return copied_node->next;
    }
    
    
public:
    Node* copyRandomList(Node* head) {
        return copyRandom_helper(head);
        
    }
};
