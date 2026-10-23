
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        stack<pair<TreeNode*, TreeNode*>> st;

        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        auto current1 = root1;
        auto current2 = root2;
        st.push({current1, current2});

        while (!st.empty()) {

            current1 = st.top().first;
            current2 = st.top().second;
            st.pop();

            current2->val = current1->val + current2->val;

            if (current1->left != nullptr) {
                if (current2->left != nullptr) {
                    st.push({current1->left, current2->left});
                } else {
                    current2->left = current1->left;
                }
            }

            if (current1->right != nullptr) {
                if (current2->right != nullptr) {
                    st.push({current1->right, current2->right});
                } else {
                    current2->right = current1->right;
                }
            }
        }

        return root2;
    }
};
