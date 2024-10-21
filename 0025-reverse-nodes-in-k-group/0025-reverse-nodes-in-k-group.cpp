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
    int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL) return head;
        if(head->next==NULL) return head;

        ListNode* temp = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int pos = 0;

        int l = getLength(head);
        if(l<k){
            return head;
        }

        while(pos<k){
            pos++;
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }


        ListNode* recursionkaAns = NULL;
        if(temp!=NULL){
            recursionkaAns = reverseKGroup(temp,k);

            head->next = recursionkaAns;
        }

        return prev;

    }
};