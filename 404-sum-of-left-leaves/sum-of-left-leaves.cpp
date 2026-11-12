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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == nullptr)
            return 0;

        stack<TreeNode*> st;
        st.push(root);

        int sum = 0;

        while( !st.empty() ){

            auto curr = st.top();
            st.pop();

            if ( curr->left != nullptr && (curr->left->left == nullptr && curr->left->right == nullptr) ){
                sum = sum + curr -> left->val ;
            }
            else {
                if (curr->left != nullptr){
                    st.push(curr->left); 
                }
            }
            if (curr->right != nullptr){
                    st.push(curr->right); 
                }
        }
        return sum;
    }
};