class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Basic condition if head is NULL
        if(head == NULL) return head;
        
        // Get the length of the list
        int len = getLength(head);
        
        // If the length is less than n, return head as no removal is needed
        if(len < n) return head;
        
        // Special case: if removing the first node (head)
        if(len == n) {
            return head->next; // The new head will be the second node
        }
        
        // Traverse to the node just before the one we need to remove
        int pos = 1;
        int it = len - n;

        ListNode* curr = head;
        
        // Move to the (len-n)th node
        while(pos < it) {
            curr = curr->next;
            pos++;
        }
        
        // Remove the nth node from the end
        ListNode* nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;  // Skip the nth node
        
        return head;
    }
};
