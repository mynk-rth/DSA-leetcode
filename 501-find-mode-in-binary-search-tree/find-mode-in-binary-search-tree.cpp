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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> inorder;

        auto current_node= root;  
        stack<TreeNode*> st;      
        
        while (current_node != nullptr || !st.empty()){

            while(current_node != nullptr){
                st.push(current_node);            
                current_node = current_node->left;
            }
            current_node = st.top();
            st.pop();
            inorder.push_back(current_node->val);
            current_node = current_node->right;
        }
        
        map<int, int> freq;
        int maxFreq = 0;

        for (int i : inorder) {
            freq[i]++;
            maxFreq = max(maxFreq, freq[i]);
        }

        vector<int> output;
        for (auto p : freq) {
            if (p.second == maxFreq) {
                output.push_back(p.first);
            }
        }

        return output;
        
    }
};