
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


       
    ListNode* dummy = new ListNode(0);
dummy->next = head;
 ListNode* i = dummy;
        ListNode* j = dummy;

    for (int k = 0; k < n; k++) {
    j = j->next;
}

    while (j != NULL && j->next != NULL) {
    i = i->next;
    j = j->next;
}
     i->next = i->next->next;

        return dummy->next;







    }
};