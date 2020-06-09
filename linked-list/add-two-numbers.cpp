//2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carrier = 0;
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
                      
        while (l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            int sum = v1 + v2 + carrier;
            
            carrier = sum / 10;
                            
            cur->next = new ListNode(sum % 10);
                
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            
            cur = cur->next;
        }
        
        if (0 != carrier)
            cur->next = new ListNode(carrier);
        
        return newHead->next;
    }
};