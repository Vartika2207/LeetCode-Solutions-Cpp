/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // app1: use set to store and while traversing the list 
    // if any node appears again return the it -> time: O(n), space: O(n)

    // app2: use turtle method -> time: O(n), space: O(!)
    //                    _l2___x
//intuition:if o'---l1--o/      \
    //                   \______/  
    // if x is the meeting pnt for fast and slow then o'--x is l1 and o'--o is l1 then the distace-slow-o'-x = l2+l1, 
    // fast will complete the circe few times (ntime) and will meet slow at o distace-fast-o'-o-x-o-x = slow-distance + n*loop since fast travel more
    // 2 * slow travel = fast
    // 2(l1+l2) = l1+l2+n*loop => l1+l2=loop*n => l1=n*loop-l2  hence slow o'--o == x--o clockwise and this is loop pnt
    ListNode *detectCycleApp2(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        return detectCycleApp2(head);
    }
};
