//141. Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        
        //慢指针走一步，快指针走两步
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        //快慢指针如果相遇则必有环
        while (slow != fast) {
            if (!fast || !fast->next)
                return false;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};