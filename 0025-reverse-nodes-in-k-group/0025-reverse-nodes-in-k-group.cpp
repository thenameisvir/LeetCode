class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        // First, check if there are at least k nodes left to reverse
        int count = 0;
        curr = head;
        while (count < k && curr != NULL) {
            curr = curr->next;
            count++;
        }
        if (count < k) {
            return head; // Not enough nodes to reverse, return as is
        }

        // Reverse k nodes
        curr = head;
        count = 0;
        while (count < k) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        // Recursively reverse the remaining nodes, and connect the reversed part
        if (temp != NULL) {
            head->next = reverseKGroup(temp, k);
        }

        return prev; // prev is now the new head of the reversed group
    }
};
