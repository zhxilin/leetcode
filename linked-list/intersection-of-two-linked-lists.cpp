//160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int cntA = 0, cntB = 0;
        //比较两个链表的长度，将较长的链表步进到与较短的一样长，然后齐步走，找到相同的节点
        while (p1) {
            cntA++;
            p1 = p1->next;
        }
        
        while (p2) {
            cntB++;
            p2 = p2->next;
        }
        
        p1 = headA, p2 = headB;
        
        if (cntB > cntA) {
            int diff = cntB - cntA;
            while (diff--) {
                p2 = p2->next;
            }
        } else if (cntB < cntA) {
            int diff = cntA - cntB;
            while (diff--) {
                p1 = p1->next;
            }
        }
        
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};