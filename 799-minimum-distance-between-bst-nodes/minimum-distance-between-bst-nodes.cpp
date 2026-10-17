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
    int minDiffInBST(TreeNode* root) {
        
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

        int minDist = INT_MAX;
        for (int i=1 ; i<inorder.size(); i++){
            minDist = min(minDist, inorder[i]-inorder[i-1]);
        }

        return minDist;
    }
};