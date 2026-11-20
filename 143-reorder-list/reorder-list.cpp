class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // Step 1: Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split List
        ListNode* curr = slow->next;
        slow->next = NULL;

        // Step 3: Reverse Second Half
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 4: Merge
        ListNode* first = head;  // 4        // 1->2->null
        ListNode* second = prev;  // 2

        while(second != NULL) {  //

            ListNode* next = first->next;  // 2

            first->next = second; //1->4 
            first = second;

            second = next;  
        }
    }
};