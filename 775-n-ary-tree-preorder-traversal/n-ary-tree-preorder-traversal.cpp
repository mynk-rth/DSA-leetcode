/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            auto curr = st.top();
            st.pop();

            ans.push_back(curr->val);                                           // preorder NLR

           int n = curr->children.size();
            for (int i = 0; i < n; i++) {
                st.push(curr->children[n - 1 - i]);
            }
        }

        return ans;
    }
};