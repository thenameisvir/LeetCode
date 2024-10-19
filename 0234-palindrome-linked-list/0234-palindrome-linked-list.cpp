class Solution {
public:
    // Function to reverse the linked list
    void reverseList(ListNode* &head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }

    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // Function to compare two halves of the linked list
    bool compareLists(ListNode* head1, ListNode* head2) {
        while (head2 != nullptr) {  // Only need to check the second half
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle of the linked list
        ListNode* middle = findMiddle(head);

        // Reverse the second half
        ListNode* secondHalf = middle;
        reverseList(secondHalf);

        // Compare the first half with the reversed second half
        bool result = compareLists(head, secondHalf);

        // Optionally reverse the second half again to restore the original list
        reverseList(secondHalf);

        return result;
    }
};
