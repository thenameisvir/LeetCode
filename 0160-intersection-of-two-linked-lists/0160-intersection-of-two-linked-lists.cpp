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
            if(a==b){
                return a;
            }
            a = a->next;
            b = b->next;

        }

        if(a->next==0){
            // B is bigger
            int Blen = 0;
            // we got the length of B which is how much big from the start
            while(b->next){
                Blen++;
                b = b->next;
            }
            // now place the B at the good point
            while(Blen--){
                headB = headB->next;
            }

        }
        else{
            // A is bigger
            int Alen = 0;
            // we got the length of A which is how much big from the start
            while(a->next){
                Alen++;
                a = a->next;
            }
            // now place the a at the good position
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