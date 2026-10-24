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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if( root == nullptr ){
            return root;
        }
        stack<TreeNode*> st;
        
        st.push(root);

        while (!st.empty()) {

            auto current_node = st.top();
            st.pop();

            swap(current_node->left, current_node->right);

            if (current_node->left != nullptr) {
                st.push(current_node->left);
            }

            if (current_node->right != nullptr) {
                st.push(current_node->right);
            }
        
        }

        return root; 
    }
};