//116. Populating Next Right Pointers in Each Node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //前序遍历
        if (!root || !root->left)
            return root;
        
        //一二层：将根的左子节点与右子节点连接(2->3，4->5，6->7, etc.）
        root->left->next = root->right; 
        
        //二三层：如果根节点已连接next，则将右子节点与根的next的左子节点连接（5->6）
        if (root->next)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};