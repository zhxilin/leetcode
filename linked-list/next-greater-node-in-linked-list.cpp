//1019. Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {0};
        
        stack<int> stack;
        vector<int> input;
        
        ListNode* p = head;
        while (p) {
            input.push_back(p->val);
            p = p->next;
        }
        
        vector<int> result(input.size());
        
        for (int i = input.size() - 1; i >= 0; --i) {
            while(!stack.empty() && input[i] >= stack.top()) 
                stack.pop();
            
            if (!stack.empty())
                result[i] = stack.top();
            
            stack.push(input[i]);
        }
        
        return result;
    }
};