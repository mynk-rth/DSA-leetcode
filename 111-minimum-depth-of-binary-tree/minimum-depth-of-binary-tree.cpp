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
    int minDepth(TreeNode* root) {
        
        if (root == nullptr){
            return 0;
        }

        stack<pair<TreeNode*, int>> st;
        st.push({root,1});

        int mindepth = INT_MAX;

        while(!st.empty()){

            auto [current,node] = st.top();
            st.pop();

            if(current->left == nullptr && current->right == nullptr){
                mindepth = min(mindepth,node);
            }

            if(current->left != nullptr){
                st.push({current->left,node+1});
            }

            if(current->right != nullptr){
                st.push({current->right,node+1});
            }
        }
        return mindepth;
    }
};