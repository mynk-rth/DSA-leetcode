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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<string> ans1 = preorder(p);  // 1 2 null null 3
        vector<string> ans2 = preorder(q);  // 1 2 null null 3

        return ans1 == ans2;
    }

    vector<string> preorder(TreeNode* root) {
        vector<string> ans;
        stack<TreeNode*> st; // 3 
        st.push(root);

        while (!st.empty()) {

            auto current = st.top();
            st.pop();

            if (current == nullptr) {
                ans.push_back("NULL");
                continue;
            }

            ans.push_back(to_string(current->val));
            st.push(current->right);
            st.push(current->left);
        }

        return ans;    // 1 2  // 1 null 2
    }
};




