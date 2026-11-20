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
    ListNode* doubleIt(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        // Step 1: Reverse Linked List
        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;

       // Step 2: Multiply each digit by 2
        ListNode* temp = head;
        int carry = 0;

        while(temp != NULL) {

            int sum = temp->val * 2 + carry;

            temp->val = sum % 10;
            carry = sum / 10;

            if(temp->next == NULL)
                break;

            temp = temp->next;
        }

        // Add remaining carry
        if(carry > 0)
            temp->next = new ListNode(carry);

         // Step 3: Reverse again
        prev = NULL;
        curr = head;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};