ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp = new ListNode(-1);
    ListNode *res = temp;
    int carry = 0;
    if (l1 == NULL && l2 == NULL)
        return l1;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *r1 = l1;
    ListNode *r2 = l2;
    while (r1 != NULL || r2 != NULL)
    {
        if (r1 != NULL && r2 != NULL)
        {
            int sum = r1->val + r2->val + carry;
            if (sum <= 9)
            {
                temp->next = new ListNode(sum);
                carry = 0;
            }
            else
            {
                int o = sum % 10;
                sum = sum / 10;
                carry = sum % 10;
                temp->next = new ListNode(o);
            }
            temp = temp->next;
            r1 = r1->next;
            r2 = r2->next;
        }
        else
        {
            if (r1 != NULL)
            {
                int sum1 = r1->val + carry;
                if (sum1 <= 9)
                {
                    temp->next = new ListNode(sum1);
                    carry = 0;
                }
                else
                {
                    int o1 = sum1 % 10;
                    sum1 = sum1 / 10;
                    carry = sum1;
                    temp->next = new ListNode(o1);
                }

                r1 = r1->next;
                temp = temp->next;
            }
            else
            {
                if (r2 != NULL)
                {
                    int sum2 = r2->val + carry;
                    if (sum2 <= 9)
                    {
                        temp->next = new ListNode(sum2);
                        carry = 0;
                    }
                    else
                    {
                        int o2 = sum2 % 10;
                        sum2 = sum2 / 10;
                        carry = sum2;
                        temp->next = new ListNode(o2);
                    }

                    r2 = r2->next;
                    temp = temp->next;
                }
            }
        }
    }
    if (carry != 0)
        temp->next = new ListNode(carry);

    return res->next;
}