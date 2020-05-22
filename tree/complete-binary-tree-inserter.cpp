//919. Complete Binary Tree Inserter
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        m_Tree = root;
    }
    
    int insert(int v) {
        
        //BFS逐层检查，遇到空子节点插入即可一直保持完全二叉树属性
        queue<TreeNode*> q;
        q.push(m_Tree);
        
        TreeNode* node;
        
        while (!q.empty()) {
            
            node = q.front();
            q.pop();
            
            if (!node->left) {
                node->left = new TreeNode(v);
                break;
            }
            
            if (!node->right) {
                node->right = new TreeNode(v);
                break;
            }
                
            if (node->left)
                q.push(node->left);
            
            if (node->right)
                q.push(node->right);
        }
        
        return node->val;
    }
    
    TreeNode* get_root() {
        return m_Tree;
    }

private:
    TreeNode* m_Tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */