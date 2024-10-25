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
    ListNode* swapNodes(ListNode* head, int k) {
        // Bsdic conditions are applicable
        int len = getLength(head);
        if(k>len) return head;
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        int n1 = k;

        while(n1>1){
            temp1 = temp1->next;
            n1--;
        }

        int num1 = temp1->val;


        int n2 = len-k+1;

        while(n2>1){
            temp2 = temp2->next;
            n2--;
        }

        int num2 = temp2->val;


        temp1->val = num2;
        temp2->val = num1;

        return head;

    }
};