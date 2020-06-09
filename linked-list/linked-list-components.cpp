//817. Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> mx;
        for (int i : G) {
            mx.insert(i);
        }
        
        int result = 0;
        
        ListNode* cur = head;
        while (cur) {
            if (mx.count(cur->val) && (!cur->next || !mx.count(cur->next->val)))
                result++;
            cur = cur->next;
        }
        return result;
    }
};