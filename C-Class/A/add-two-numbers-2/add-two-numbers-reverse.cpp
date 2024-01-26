
#include <iostream>
#include <typeinfo>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution
{
    public:
        ListNode* reverseList(ListNode *l)
        {
            ListNode *previous = nullptr;
            ListNode *nexter;
        
            while (l != nullptr)
            {
                nexter = l->next;
                l->next = previous;
                previous = l;
                l = nexter;
            }
            return previous;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode* dummyHead = new ListNode(0);
            ListNode* current = dummyHead;

            l1 = reverseList(l1);
            l2 = reverseList(l2);

            int carry = 0;
            int sum = 0;

            while (l1 != nullptr || l2 != nullptr || carry == 1)
            {
                sum = carry;

                if (l1 != nullptr)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }

                if (sum >= 10)
                {
                    sum %= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }

                current->next = new ListNode(sum);
                current = current->next;
            }   
            
            // std::cout << typeid(dummyHead).name() << std::endl; //   -> 8ListNode
            // std::cout << typeid(dummyHead.next).name() << std::endl; //  -> P8ListNode
            // std::cout << typeid(current).name() << std::endl;    //  -> P8ListNode
            // std::cout << typeid(current->next).name() << std::endl;  //  ->  P8ListNode

            ListNode* result = dummyHead->next;
            delete dummyHead;
            return reverseList(result);
        }
};

int main()
{
    // Test Case:
    // Input: l1 = [3,4,2], l2 = [4,6,5]
    // Output: [8,0,7]
    // Explanation: 342 + 465 = 807.

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