//82. Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) 
            return head;
        
        //创建一个辅助节点指向原链表的头
        ListNode* newHead = new ListNode(-1);
        
        ListNode* p = newHead;
        
        //移动原链表的头，跳过重复的节点
        while (head) {
            if (head->next && head->val == head->next->val) {
                int v = head->val;
                while (head && head->val == v) {
                    head = head->next;
                }
            } else {
                p->next = head;
                p = p->next;
                head = head->next;
            }
        }
        
        //[1,2,2]处理此种情况，最终的p落在1上，而head的循环已经跳过了全部2，应该最后把p的下一个指向空
        p->next = NULL;
                
        return newHead->next;
    }
};