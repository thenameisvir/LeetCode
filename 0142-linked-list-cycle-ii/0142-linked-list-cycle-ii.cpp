class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer by 2 steps and slow pointer by 1 step
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, cycle exists
            if(slow == fast) {
                break;
            }
        }

        // If fast reached NULL, it means there is no cycle
        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Move slow to head, and move both pointers at the same speed
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Both pointers meet at the start of the cycle
        return slow;
    }
};
