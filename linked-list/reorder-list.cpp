//143. Reorder List
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        //利用双指针找出中点，并翻转中点到结尾
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = reverse(slow);
        
        //前后两段链表交错连接
        while (p1 && p2) {
            ListNode* tmp = p1->next;
            p1->next = p2;
            p1 = tmp;
            
            tmp = p2->next;
            p2->next = p1;
            p2 = tmp;
        }
        
        if (p1)
            p1->next = NULL;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            
            prev = head;
            head = next;
        }
        
        return prev;
    }
};