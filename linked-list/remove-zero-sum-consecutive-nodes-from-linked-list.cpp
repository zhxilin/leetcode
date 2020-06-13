//1171. Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = head;
    
        int sum = 0;
        while (cur) {
            sum = sum + cur->val;
        
            if (0 == sum)
                prev->next = cur->next;
            
            cur = cur->next;
            
            if (!cur) {
                prev = prev->next;
                
                if (!prev) 
                    break;
            
                cur = prev->next;
                sum = 0;
            }
        }
    
        return dummy->next;
    }
};