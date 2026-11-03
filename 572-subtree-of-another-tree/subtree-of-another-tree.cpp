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

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            auto current = st.top();
            st.pop();

            if (current->val == subRoot->val) {

                stack<pair<TreeNode*, TreeNode*>> s;
                s.push({current, subRoot});
                bool same = true;

                while (!s.empty()) {

                    auto [node_root, node_subroot] = s.top();
                    s.pop();

                    if (node_root == nullptr && node_subroot == nullptr)
                        continue;

                    if (node_root == nullptr || node_subroot == nullptr || node_root->val != node_subroot->val) {
                        same = false;
                        break;
                    }
                    s.push({node_root->left, node_subroot->left});
                    s.push({node_root->right, node_subroot->right});
                }
                if (same) return true;
            }

            if (current->left != nullptr)
                st.push(current->left);
            if (current->right != nullptr)
                st.push(current->right);
        }

        return false;
    }
};
