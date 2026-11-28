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
    TreeNode* trimBST(TreeNode* root, int low, int high) {

        while (root != nullptr && (root->val < low || root->val > high)) {

            if (root->val < low)
                root = root->right;
            else
                root = root->left;
        }

        auto curr = root;
        while (curr != nullptr) {

            while (curr->left != nullptr && curr->left->val < low) {
                curr->left = curr->left->right;
            }
            while (curr->left != nullptr && curr->left->val > high) {
                curr->left = curr->left->left;
            }
            curr = curr->left;
        }

        curr = root;
        while (curr != nullptr) {

            while (curr->right != nullptr && curr->right->val > high) {
                curr->right = curr->right->left;
            }
            while (curr->right != nullptr && curr->right->val < low) {
                curr->right = curr->right->right;
            }
            curr = curr->right;
        }
        return root;
    }
};
