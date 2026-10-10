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
    int maxDepth(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;

        if(root==nullptr){
            return 0;
        }
        else
           q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                auto root = q.front();
                q.pop();
                level.push_back(root->val);

                for (auto child : root->children){
                    q.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans.size();
    }
};