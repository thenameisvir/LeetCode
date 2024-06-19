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
    ListNode* sortList(ListNode* head) {
        
        ListNode* temp = head;
        vector<int>v;
        while(temp!=NULL){
            int a = temp->val;
            v.push_back(a);
            temp = temp->next;
        }
        
       std::sort(v.begin(), v.end());
        
        temp = head;
        int i=0;
        while(temp!=NULL){
            temp->val = v[i];
            temp = temp->next;
            i++;
        }
        
        return head;
        
    }
};