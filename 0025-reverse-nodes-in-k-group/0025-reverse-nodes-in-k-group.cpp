class Solution {
public:
    int getLength(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }


        return len;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        // if(head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        int pos = 0;

        int len = getLength(head);
        if(len<k){
            return head;
        }

        // do one task and leave it to recursion

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