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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        stack<pair<TreeNode*, bool>> st;        // 1f 1t 3f 2f
        unordered_map<TreeNode*, int> height;

        st.push({root, false});

        int diameter = 0;

        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if (node == nullptr) continue;

            if (!visited) {
                st.push({node, true});
                st.push({node->right, false});
                st.push({node->left, false});
            }
            else {
                int left = height[node->left];
                int right = height[node->right];

                diameter = max(diameter, left + right);

                height[node] = 1 + max(left, right);
            }
        }

        return diameter;
    }
};