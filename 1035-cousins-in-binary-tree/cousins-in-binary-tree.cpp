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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int n = q.size();

            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            for (int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                TreeNode* parent = p.second;

                if (node->val == x) parentX = parent;
                if (node->val == y) parentY = parent;

                if (node->left)
                    q.push({node->left, node});

                if (node->right)
                    q.push({node->right, node});
            }

            if (parentX || parentY)
                return parentX != nullptr &&
                       parentY != nullptr &&
                       parentX != parentY;
        }

        return false;
    }
};