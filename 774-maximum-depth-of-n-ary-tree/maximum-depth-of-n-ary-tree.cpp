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

        int level = 0;
        queue<Node*> q;

        if(root==nullptr){
            return 0;
        }
        else
           q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto root = q.front();
                q.pop();

                for (auto child : root->children){
                    q.push(child);
                }
            }
            level++;
        }
        return level;
    }
};