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
        while(temp){
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        // basic condition
        if(!head) return head;
        
        int len = getLength(head);
        // actual rotated value
        int rotate = (k%len);

        // One more basic condition
        if(rotate==0) return head;

        // Get the position for the following 
        int position = len-rotate-1;

        ListNode* newLastNode = head;

        for(int i=0;i<position;i++){
            newLastNode = newLastNode->next;
        }

        ListNode* newHead = newLastNode->next;

        newLastNode->next = NULL;

        ListNode* it = newHead;
        while(it->next){
            it = it->next;
        }

        it->next = head;


        return newHead;

    }
};