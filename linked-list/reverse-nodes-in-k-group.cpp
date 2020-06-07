//25. Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        
        //计算总节点数
        int leftCount = 0;
        ListNode* tmp = head;
        while (tmp) {
            leftCount++;
            tmp = tmp->next;
        }
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        ListNode* beforeRevert;
        ListNode* lastRevert;
        
        bool isFirstGroup = true;
        
        while (cur && leftCount >= k) {
            beforeRevert = prev;
            lastRevert = cur;
            
            //每k个做一组翻转操作
            int cnt = 0;
            while (cur && cnt < k) {
                ListNode* next = cur->next;
                cur->next = prev;
                
                prev = cur;
                cur = next;
                cnt++;
            }
            
            //此时的状态：
            //beforeRevert指向第0个节点
            //lastRevert指向第1个节点
            //prev指向第k个节点
            //cur指向第k+1个节点
            //其中1到k已翻转，需要重新连接翻转部分和未翻转部分
            if (beforeRevert)
                beforeRevert->next = prev;
            
            if (lastRevert)
                lastRevert->next = cur;            
            
            //注意：如果是第一组，需要调整头指针，因为第一组翻转后，第k个节点是新的头节点            
            if (isFirstGroup) {
                head = prev;
                isFirstGroup = false;
            }
            
            //此时4个指针已调整完毕，准备进入下一轮循环
            prev = lastRevert;
            
            leftCount -= k;
        }
        
        return head;
    }
};