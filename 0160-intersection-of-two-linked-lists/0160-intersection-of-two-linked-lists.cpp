class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        map<ListNode*,int>mp;
        ListNode* ans = nullptr;
        ListNode* curr = head1;
        while(curr){
            mp[curr] = 1;
            curr = curr->next;
        }
        curr = head2;
        while(curr){
            if(mp.count(curr)) return curr;
            curr = curr->next;
        }

        return nullptr;
    }
};