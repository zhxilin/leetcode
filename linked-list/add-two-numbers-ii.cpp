//445. Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while (p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        
        while (p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        
        int carrier = 0;
        ListNode* cur = NULL;
        
        while (!s1.empty() || !s2.empty() || 0 != carrier) {
            int v1 = s1.empty() ? 0 : s1.top();
            int v2 = s2.empty() ? 0 : s2.top();
            
            int sum = v1 + v2 + carrier;
            carrier = sum / 10;
            
            ListNode* node = new ListNode(sum % 10);
            node->next = cur;
            cur = node;
            
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
        }
        
        return cur;
    }
};