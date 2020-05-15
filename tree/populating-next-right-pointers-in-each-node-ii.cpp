//117. Populating Next Right Pointers in Each Node II
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
        if (!root || !root->left && !root->right)
            return root;
        
        //一二层：将根的左子节点与右子节点连接(2->3，4->5, etc.）        
        if (root->left && root->right) 
            root->left->next = root->right;
        
        //node为root的子节点中的最右节点
        Node* node = root->right ? root->right : root->left;
        
        //找出node节点要连接的下一个节点的父节点，通过root的next查找，顺延root->next的左右子节点都为空的点
        Node* nextRoot = root->next;
        while (nextRoot && !nextRoot->left && !nextRoot->right) {
            nextRoot = nextRoot->next;
        }
        
        //如果存在这样的nextRoot父节点，则将当前要处理的node节点连接到该nextRoot的最左子节点
        if (nextRoot)
            node->next = nextRoot->left ? nextRoot->left : nextRoot->right;
                
        //注意dfs时右子节点先处理，因为需要先保证父节点的next都处理完才可进入下一层
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};