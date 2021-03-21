//1669. Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        ListNode* tail = list1;
        ListNode* list2Tail = list2;
        
        while (list2Tail && list2Tail->next) {
            list2Tail = list2Tail->next;
        }
        
        for (int i = 0; i < b; ++i) {
            if (i < a - 1)
                head = head->next;
            
            tail = tail->next;
        }
        
        head->next = list2;
        list2Tail->next = tail->next;
        tail->next = nullptr;
        
        return list1;
    }
};


static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
