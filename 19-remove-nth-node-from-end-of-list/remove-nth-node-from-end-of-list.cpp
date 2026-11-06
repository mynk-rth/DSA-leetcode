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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }//len =5

        if (len == n) {
            return head->next;
        } // 5==5 // 2-3-4-5

        temp = head;

        for (int i = 1; i < len - n; i++) { //1< 5-2 =3
            temp = temp->next;
        }// temp=3
        temp->next = temp->next->next;
        //3 -> 5
        return head;
    }
};