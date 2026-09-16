
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
          if (head == NULL)
            return head;

  ListNode* i = head;
 while (i->next != NULL) {

    if (i->val == i->next->val) {
        i->next = i->next->next;
    }
    else {
        i = i->next;
    }
}

 return head;


    }
};