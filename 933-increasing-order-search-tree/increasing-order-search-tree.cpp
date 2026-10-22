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
    TreeNode* increasingBST(TreeNode* root) {

        vector<int> inorder;
        auto current_node= root;  
        stack<TreeNode*> st;      
        
        while (current_node != nullptr || !st.empty()){

            while(current_node != nullptr){
                st.push(current_node);            
                current_node = current_node->left;
            }
            current_node = st.top();
            st.pop();
            inorder.push_back(current_node->val);
            current_node = current_node->right;
        }

        auto ROOT = new TreeNode(inorder[0]);
        auto current = ROOT;

        for ( int i=1; i<inorder.size(); i++) {
            TreeNode* new_node = new TreeNode(inorder[i]);
            
            current->right = new_node;

            current = current->right;
        }
        return ROOT;
    }
};