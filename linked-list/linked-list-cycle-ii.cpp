//142. Linked List Cycle II
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
        if (!head || !head->next)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                break;
        }
        
        if (slow!=fast) 
            return NULL;
        
		if (!slow || !slow->next)
            return NULL;
        
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};