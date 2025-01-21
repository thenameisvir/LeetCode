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
    int lengthIs(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }

        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
     // phir agye hum huehuehue
     if(!head) return head;
     if(!head->next) return head; // means ki single element hai toh reverse kaise kre

     ListNode* curr = head;
     ListNode* temp = NULL;
     ListNode* prev = NULL;

     int pos = 0;
     if(lengthIs(head)<k) return head;

     while(pos<k){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        pos++;
     }

     // yaha tk maine k reverse krdi hai ab baki ka recursion karega kaam
     ListNode* recursionKaAns = NULL;

     if(temp){
        recursionKaAns = reverseKGroup(curr,k);
        // aur dhyan rkho sbse main point , attatch karna mt bhulna
        head->next = recursionKaAns;
     }


     return prev;

    }
};