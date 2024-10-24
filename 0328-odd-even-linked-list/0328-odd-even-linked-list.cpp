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
        if(!head || head->next==NULL) return head;

        ListNode* head1 = head; // Odd nodes pr jayega ye
        ListNode* head2 = head->next; // Even nodes pr jayega ye

        // succefully stored the second head , which we have to add in the end 
        ListNode* stored = head2;

        while(head2 && head2->next){
            head1->next = head2->next;
            head2->next = head2->next->next;
            head1 = head1->next;
            head2 = head2->next;
        }

        head1->next = stored;
        return head;





    }
};