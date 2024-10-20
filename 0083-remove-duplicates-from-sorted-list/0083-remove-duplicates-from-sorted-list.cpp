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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* newNode = temp->next;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->val==newNode->val){
                temp->next = newNode->next;
                newNode = newNode->next;
            }
            else{
                temp = temp->next;
                newNode = newNode->next;
            }

        }

        return head;

    }
};