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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        stack<TreeNode*> st;
        st.push(cloned);

        while (!st.empty()) {

            auto curr = st.top();
            st.pop();

            if (curr->val == target->val)
                return curr;

            if (curr->right != nullptr)
                st.push(curr->right);

            if (curr->left != nullptr)
                st.push(curr->left);
        }

        return nullptr;
    }
};