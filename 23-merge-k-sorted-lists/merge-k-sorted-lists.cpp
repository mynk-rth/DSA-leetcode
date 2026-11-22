/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> ans;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(ListNode* curr : lists) {

            while(curr != NULL) {
                ans.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(ans.begin(), ans.end());

        for(int digit : ans) {

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
        }

        return dummy->next;
    }
};
