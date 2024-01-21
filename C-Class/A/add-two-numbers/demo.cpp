   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode dummyHead(0);
        ListNode *current = &dummyHead;

        while (carry || l1 || l2)
        {
            carry += (l1? l1->val: 0) + (l2? l2->val: 0);
            current->next = new ListNode(carry % 10);
            current = current->next;

            carry /= 10;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        return dummyHead.next;
    }