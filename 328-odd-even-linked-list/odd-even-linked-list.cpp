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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ODD = head; //1

        auto EVEN = head->next;  // 2
        auto Firstnode_Even = EVEN;  //2

        while(EVEN != NULL && EVEN->next != NULL){

            ODD->next = EVEN->next;  //
            ODD = ODD->next;

            EVEN->next = ODD->next;
            EVEN = EVEN->next;
        }

        ODD->next = Firstnode_Even;

        return head;
    }
};