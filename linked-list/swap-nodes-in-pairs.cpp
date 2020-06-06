//24. Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        //定义一个新的头节点指向原链表的头，当头2个节点交换后，可以通过这个节点快速找到新的头
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        
        ListNode *p1 = newHead, *p2 = head;
       
        while (p2 && p2->next) {
            //交换p1和p2
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            
            //为下一轮交换准备p1,p2
            p1 = p2;
            p2 = p2->next;
        }
                
        return newHead->next;
    }
};