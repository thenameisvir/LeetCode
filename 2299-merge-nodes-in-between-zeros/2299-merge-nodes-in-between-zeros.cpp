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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(); // dummy node for the new list
        ListNode* temp2 = dummy;
        ListNode* temp = head->next; // skip the initial zero node
        int sum = 0;
        
        while (temp != nullptr) {
            if (temp->val != 0) {
                sum += temp->val;
            } else {
                temp2->next = new ListNode(sum);
                temp2 = temp2->next;
                sum = 0;
            }
            temp = temp->next;
        }
        
        return dummy->next; // return the head of the new list
    }
};
