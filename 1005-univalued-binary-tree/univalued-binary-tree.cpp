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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        auto node = root->val;

        while( !q.empty() ){
            auto current = q.front();
            q.pop();

            if ( current->val != node ) {
                return false;
            }

            if (current->right != nullptr)
                q.push(current->right);

            if (current->left != nullptr)
                q.push(current->left);
        }
        return true;
    }
};