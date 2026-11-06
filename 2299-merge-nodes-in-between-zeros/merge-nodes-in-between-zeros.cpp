/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */                                                                                                                                                                                            class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int sum = 0;

        head = head->next;   // First 0 skip

        while (head != NULL) {

            if (head->val == 0) {

                temp->next = new ListNode(sum);
                temp = temp->next; //0 4 11
                                      //  temp 

                sum = 0;
            }
            else {

                sum += head->val;
            }//sum = 11

            head = head->next;//0
        }

        return dummy->next;
    }
};