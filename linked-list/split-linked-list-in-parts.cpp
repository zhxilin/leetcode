//725. Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {     
        vector<ListNode*> result;
        
        int cnt = 0;
        ListNode* cur = root;
        while (cur) {
            cnt++;
            cur = cur->next;
        }
        
        int width = cnt / k; //每一部分的最小宽度
        int mod = cnt % k; //前mod部分宽度+1
        
        cur = root;
        
        for (int i = 0; i < k; ++i) {
            ListNode* node = cur;
            int curWidth = width + (i < mod ? 1: 0);
            for (int j = 0; j < curWidth - 1; ++j) {
                if (cur)
                    cur = cur->next;
            }
            //cur当前指向每部分最后一个节点，将其与下一个节点断开
            if (cur) {
                ListNode* prev = cur;
                cur = cur->next;
                prev->next = NULL;
            }
            result.push_back(node);
        }
        
        return result;
    }
};