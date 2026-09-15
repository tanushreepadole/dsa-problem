class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* i = head;
        ListNode* j = head;

        // Find middle
        while (j != NULL && j->next != NULL) {
            i = i->next;
            j = j->next->next;
        }

        // Choose where second half starts
        ListNode* prev = NULL;
        ListNode* curr;

        if (j == NULL)
            curr = i;        // EVEN
        else
            curr = i->next;  // ODD

        // Reverse second half
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Compare
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};