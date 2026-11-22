
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* curr = head;

        int length = 0;

        // Step 1: Find length and last node
        while (curr != NULL) {
            curr = curr->next;
            length++;
            if(curr->next == NULL){
                length++;
                break;
            }
               
        }

        // Step 2: Reduce rotations
        k = k % length;


        // Step 3: Make circular Linked List
        curr->next = head;

        // Step 4: Find new tail
        int n = length - k - 1;

        ListNode* curr1 = head;

        while (n--) {
            curr1 = curr1->next;
        }

        // Step 5: Break circular Linked List
        ListNode* newHead = curr1->next;
        curr1->next = NULL;

        return newHead;
    }
};
