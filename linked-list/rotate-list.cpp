//61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        
        // k = k % 总节点数 -> 余数的含义为即为倒数第k个节点为最终的头节点
        //求总节点数
        int count = 1;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            count++;
        }
        
        //把最后一个节点和当前的头连接
        p->next = head;
        
        p = head;
        
        k %= count;
        
        int n = 0;
        //找到新的尾节点
        while (n < count - k - 1) {
            n++;
            p = p->next;
        }
        
        ListNode* newHead = p->next;
        p->next = NULL;
        
        return newHead;
    }
};