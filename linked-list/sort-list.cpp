//148. Sort List
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* mid = middle(head);
        
        ListNode* r = sortList(mid->next);
        mid->next = NULL;
        ListNode* l = sortList(head);
        
        return merge(l, r);
    }

private:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l || !r) 
            return !l ? r : l;

        ListNode* node;

        if (l->val < r->val) {
            node = l;
            node->next = merge(l->next, r);
        } else {
            node = r;
            node->next = merge(l, r->next);
        }

        return node;
    }
};