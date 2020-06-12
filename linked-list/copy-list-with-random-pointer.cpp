//138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        
        unordered_map<Node*, Node*> mx;
        
        Node* node = new Node(head->val);        
        Node* newHead = node;
        
        mx[head] = node;
        mx[NULL] = NULL;
        
        while (head) {
            if (!mx.count(head->random))
                mx[head->random] = new Node(head->random->val);            
            node->random = mx[head->random];
            
            if (!mx.count(head->next))
                mx[head->next] = new Node(head->next->val);
            node->next = mx[head->next];
            
            node = node->next;
            head = head->next;
        }
        
        return newHead;
    }
};