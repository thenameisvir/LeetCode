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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , bool>mp;

        // we know that we have to interate through the secpndary pointer so we have to 
        // create a temporary pointer over here known as temp

        ListNode* temp = head;

        while(temp){
            if(mp.find(temp)!=mp.end()){
                // if the entry is present then return it simply
                return true;
            }
            else{
                // initialise the entry and mark true infront of it
                mp[temp] = true;
            }
// push the temp pointer forward
        temp = temp->next;

        }


        return false;
        
    }


    
};