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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        if (root == nullptr) {
            return ans;
        }

        stack<pair<TreeNode*, string>> st;         // 1,1
        st.push({root, to_string(root->val)});

        while (!st.empty()) {

            auto current = st.top();    // 1,1 
            st.pop();

            TreeNode* node = current.first;   // 1
            string path = current.second;     // 1

            if (node->left == nullptr && node->right == nullptr) {
                ans.push_back(path);
                continue;
            }

            if (node->right != nullptr) {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if (node->left != nullptr) {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }

        return ans;
    }
};