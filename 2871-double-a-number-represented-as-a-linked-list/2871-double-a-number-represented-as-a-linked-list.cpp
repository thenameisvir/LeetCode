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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;

        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode* temp = head;
        ListNode* prev = NULL;

        int carry = 0;
        while(temp){
            int totalSum = 2*(temp->val) + carry;
            int digit = totalSum%10;
            carry = totalSum/10;
            temp->val = digit;
            prev = temp;
            temp = temp->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
    head = reverse(head);
        return head;
    }
};