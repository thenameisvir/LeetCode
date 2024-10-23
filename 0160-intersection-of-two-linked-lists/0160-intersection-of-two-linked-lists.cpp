/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a->next&&b->next){
            a = a->next;
            b = b->next;
        }


        if(a->next==0){
            // B is greater
            // length of b
            int Blen = 0;
            // original length
            while(b->next){
                Blen++;
                b = b->next;
            }

            while(Blen--){
                headB = headB->next;
            }


        }
        else{
            int Alen = 0;
            // original length
            while(a->next){
                Alen++;
                a = a->next;
            }

            while(Alen--){
                headA = headA->next;
            }
        }


        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;

    }
};