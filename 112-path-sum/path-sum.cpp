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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto current = st.top();
            st.pop();

            TreeNode* node = current.first;
            int path_sum = current.second;

            if (node->left == nullptr && node->right == nullptr) {
                if (path_sum == targetSum) {
                    return true;
                }
            }

            if (node->right != nullptr) {
                st.push({node->right, path_sum + node->right->val});
            }

            if (node->left != nullptr) {
                st.push({node->left, path_sum + node->left->val});
            }
        }

        return false;
    }
};
