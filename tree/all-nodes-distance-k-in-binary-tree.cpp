//863. All Nodes Distance K in Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //思路：
        //1.通过DFS找出每个节点的父节点，以便于BFS遍历树时，除了左右节点外，每个节点还能访问到父节点
        unordered_map<TreeNode*, TreeNode*> mx;
        dfs(root, NULL, mx);
        
        //2.通过BFS，从目标节点出发，每个节点将左右子节点和父节点入队，
        //由于需要访问父节点的缘故，需要一个访问集合来减少重复
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        
        int level = 0;
        
        while (!q.empty()) {
            if (level++ == K) break;
            
            int size = q.size();
            while (size --) {
                TreeNode* node = q.front();
                q.pop();
                
                if (!node) continue;
                
                //左子节点
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                //右子节点
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                //父节点
                if (mx.count(node) && !visited.count(mx[node])) {
                    q.push(mx[node]);
                    visited.insert(mx[node]);
                }
            }
        }
        
        vector<int> result;
        
        while (!q.empty()) { 
            TreeNode* node = q.front();
            q.pop();
            
            if (node)
                result.push_back(node->val);
        }
        
        return result;
    }
    
private:
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mx) {
        if (!root) return;
        
        mx[root] = parent;
        dfs(root->left, root, mx);
        dfs(root->right, root, mx);
    }
};