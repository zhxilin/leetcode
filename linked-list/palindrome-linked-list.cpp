//234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        
        //双指针找到中点
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //将中点至末尾的节点翻转
        ListNode* prev = NULL;
        ListNode* cur = slow;
        
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        slow = NULL;
        
        //比较开头及中点开始的链表值顺序是否一致
        ListNode* begin = head;
        ListNode* end = prev;
        while (begin && end) {
            if (begin->val != end->val) {
                return false;
            }
            begin = begin->next;
            end = end->next;
        }
        
        return true;
    }
};