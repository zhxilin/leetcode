//92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n) return head;
                
        ListNode* prev = NULL;
        ListNode* cur = head;
        int index = 1;
        
        //记录到翻转起始前的最后一个节点。以及开始翻转的第一个节点（翻转后是最后一个节点）
        while (cur && index < m) {
            prev = cur;
            cur = cur->next;
            index++;
        }
        
        ListNode* beforeRevert = prev;
        ListNode* lastRevert = cur;
        
        //开始翻转m到n的节点
        while (cur && index <= n) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
            index++;
        }
        
        //此时的状态
        //beforeRevert指向第m-1个节点
        //lastRevert指向第m个节点
        //prev指向第n个节点
        //cur指向第n+1个节点
        //其中m到n已经翻转，需要重新连接翻转部分和未翻转部分
        if (beforeRevert)
            beforeRevert->next = prev;
        
        if (lastRevert)
            lastRevert->next = cur;
        
        //如果从开头就翻转，则链表的头应该指向第n个节点
        if (1 == m)
            head = prev;
        
        return head;
    }
};