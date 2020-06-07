//1290. Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        
        int num = 0;
        ListNode* p = head;
        while (p) {
            num = (num << 1) | p->val;
            p = p->next;
        }
        
        return num;
    }
};