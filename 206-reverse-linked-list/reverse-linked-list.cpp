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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;   //  1
        auto curr = head;

        while( curr != NULL ){  // 3  

            auto next = curr -> next;  // 3

            curr -> next = prev; 

            prev = curr;  

            curr = next;
        }
        return prev;
    }
};

// 1 -> NULL    2->1   // 2->1->Null   3->2  4->3 5->4    // 5->4->3->2->1