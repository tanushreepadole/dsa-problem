class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (i != NULL && j != NULL) {

            if (i->val <= j->val) {
                curr->next = i;
                i = i->next;
                curr = curr->next;
            }
            else {
                curr->next = j;
                j = j->next;
                curr = curr->next;
            }
        }

        // ✅ AFTER while loop
        if (i != NULL)
            curr->next = i;
        else
            curr->next = j;

        return dummy->next;
    }
};