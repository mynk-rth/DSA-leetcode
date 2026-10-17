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
        
        int minDist = INT_MAX;
        int prev = -1;

        stack<TreeNode*> st;
        auto current_node = root;

        while (current_node != nullptr || !st.empty()){

            while (current_node != nullptr) {
            st.push(current_node);
            current_node = current_node->left;
            }
            
            current_node = st.top();
            st.pop();
            
            if (prev != -1) {
                minDist = min(minDist, current_node->val - prev);
            }
            prev = current_node->val;
            current_node = current_node->right;
        }
        return minDist;
    }
};