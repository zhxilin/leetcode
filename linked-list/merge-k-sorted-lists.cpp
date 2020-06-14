//23. Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* p1, ListNode* p2) -> bool {
           return p1->val > p2->val; 
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                pq.push(lists[i]);
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            
            pq.pop();
            
            if (cur->next) 
                pq.push(cur->next);
        }
        
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};