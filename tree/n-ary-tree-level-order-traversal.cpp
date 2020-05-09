//429. N-ary Tree Level Order Traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        //BFS
        queue<Node*> q;
        q.push(root);
        
        vector<vector<int>> result;
        
        while (!q.empty()) {
            //每次循环取到的size即为当层的个数
            int size = q.size();
            vector<int> level;
            
            //按层出队，同时每个节点的子节点入队
            while (size--) {
                Node* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};