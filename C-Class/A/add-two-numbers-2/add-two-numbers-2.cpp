
#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}  
};

class Solution
{
    public:
        int listLength(ListNode *l)
        {
            int length = 0;

            while (l)
            {
                length += 1;
                l = l->next;
            }
            return length;
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            int l1_length = listLength(l1);
            int l2_length = listLength(l2);

            ListNode *dummyHead = new ListNode(0);

            int sum = 0;

            while ((l1_length > 0) && (l2_length > 0))
            {
                sum = 0;
                if (l1_length >= l2_length)
                {
                    sum += l1->val;
                    l1 = l1->next;
                    l1_length -= 1;
                }
                if (l1_length < l2_length)
                {
                    sum += l2->val;
                    l2 = l2->next;
                    l2_length -= 1;
                }
                ListNode *head = new ListNode(sum, dummyHead);
                dummyHead = head;
            }       

            ListNode *current = dummyHead;
            dummyHead = nullptr;

            int carry = 0;
            while (current != nullptr)
            {
                sum = current->val + carry;

                if (sum >= 10)
                {
                    sum %= 10;
                    carry = 1; 
                }
                else
                {
                    carry = 0;
                }

                ListNode *head = new ListNode(sum, dummyHead);
                dummyHead = head;
                current = current->next;
            }
            if (dummyHead->val == 0)
            {
                ListNode *result = dummyHead->next;
                delete dummyHead;
                return result;
            }
            else
            {
                return dummyHead;
            }
        }
};

int main()
{
    Solution solution;

//  not ListNode *l1
//  not ListNode *l2
    ListNode l1 = ListNode(3, new ListNode(4, new ListNode(2)));
    ListNode l2 = ListNode(4, new ListNode(6, new ListNode(5)));

    ListNode *result;

    result = solution.addTwoNumbers(&l1, &l2);

    int number = 0;
    while (result != nullptr)
    {
        number = number*10 + result->val;
        result = result->next;
    } 
    
    std::cout << "Number = " << number << " \n";

    return 0;

}