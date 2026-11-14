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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        int sum = 0;

        while (!st.empty()) {
            auto [node, curr] = st.top();
            st.pop();

            curr = curr * 2 + node->val;

            if (node->left == nullptr && node->right == nullptr) {
                sum += curr;
            }

            if (node->right != nullptr)
                st.push({node->right, curr});

            if (node->left != nullptr)
                st.push({node->left, curr});
        }

        return sum;
    }
};