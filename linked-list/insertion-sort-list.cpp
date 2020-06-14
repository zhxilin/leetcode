//147. Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* newHead = NULL;
        ListNode* cur = head;
        
        while (cur) {
            ListNode* next = cur->next;
            cur->next = NULL;
            
            //将独立的cur节点插入新链表正确的位置
            place(dummy, cur);
            
            cur = next;
        }
        
        newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
    
    void place(ListNode* head, ListNode* cur) {
        ListNode *prev = nullptr;
        while(head && head->val <= cur->val) {
            prev = head;
            head = head->next;
        }
        prev->next = cur;
        cur->next = head;        
    }
};