//430. Flatten a Multilevel Doubly Linked List
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        
        Node* cur = head;
        while (cur) {
            if (!cur->child) {
                cur = cur->next;
                continue;
            }
            
            //如果有子节点，先记住当前节点cur的下一个节点next，
            //dfs处理完子节点后，将子链的最后一个节点连接到next
            Node* next = cur->next;
            //展平后的cur与child节点互连
            cur->next = flatten(cur->child);
            cur->child->prev = cur;
            cur->child = NULL;
            
            //子链移动到最末，使next与子链最末节点互连
            while (cur->next) {
                cur = cur->next;
            }
                
            if (next) 
                next->prev = cur;
            
            cur->next = next;
        }
        
        return head;
    }
};