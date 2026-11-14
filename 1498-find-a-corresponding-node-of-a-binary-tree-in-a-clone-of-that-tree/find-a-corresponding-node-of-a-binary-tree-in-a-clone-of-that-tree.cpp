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

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original, cloned});

        while (!q.empty()) {

            auto [original_node, clone_node] = q.front();
            q.pop();

            if (original_node == target)
                return clone_node;

            if (original_node->left != nullptr)
                q.push({original_node->left, clone_node->left});

            if (original_node->right != nullptr)
                q.push({original_node->right, clone_node->right});
        }
        return nullptr;
    }
};