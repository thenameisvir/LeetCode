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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        vector<ListNode*>ans(k,NULL);
        int idx=0;
        if(n<k)
        {
            while(head)
            {
                ans[idx++]=head;
                ListNode* next=head->next;
                head->next=NULL;
                head=next;
            }
            return ans;
        }
        int extra=n%k;
        while(head)
        {
            ans[idx++]=head;
            if(extra>0)
            {
                for(int i=0;i<n/k;i++)
                    head=head->next;
                ListNode* next=head->next;
                head->next=NULL;
                head=next;
                extra--;
            }
            else
            {
                for(int i=1;i<n/k;i++)
                    head=head->next;
                ListNode* next=head->next;
                head->next=NULL;
                head=next;
            }
        }
        return ans;
        
        
    }
};