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
        
        unordered_map<ListNode* , bool>mapping;

        // jab bhi kisi linked list pr traverse karo toh humesha temp bana lo

        ListNode* temp = head;

        while(temp){
            // address check
            if(mapping.find(temp)!=mapping.end()){
                return true;

            }

            else{
                mapping[temp] = true;
            }

            temp = temp->next;


        }

        return false;

    }
};