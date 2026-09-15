class Solution {
public:

    int length(ListNode* head) {
        int count = 0;

        while (head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int lenA = length(headA);
        int lenB = length(headB);

        ListNode* i = headA;
        ListNode* j = headB;

        int diff = abs(lenA - lenB);

        if (lenA > lenB) {
            while (diff > 0) {
                i = i->next;
                diff--;
            }
        }
        else {
            while (diff > 0) {
                j = j->next;
                diff--;
            }
        }

        while (i != NULL && j != NULL) {

            if (i == j)
                return i;

            i = i->next;
            j = j->next;
        }

        return NULL;
    }
};