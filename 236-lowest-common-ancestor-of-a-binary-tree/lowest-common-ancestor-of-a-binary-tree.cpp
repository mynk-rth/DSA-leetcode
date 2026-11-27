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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> st;
        unordered_map<TreeNode*, TreeNode*> parent;

        st.push(root);
        parent[root] = nullptr;    

        while (!st.empty()) {
            auto curr = st.top();
            st.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                st.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                st.push(curr->right);
            }

            if (parent.count(p) && parent.count(q))
                break;
        }

        unordered_set<TreeNode*> ancestors;    
        while (p != nullptr) {   
            ancestors.insert(p);
            p = parent[p];
        }

        while (q != nullptr) {    
            if (ancestors.count(q))
                return q;
            q = parent[q];
        }
        return nullptr;
    }
};
