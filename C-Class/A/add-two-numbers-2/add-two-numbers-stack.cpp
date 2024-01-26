
#include <iostream>
#include <stack>

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
        std::stack<int> listToStack(ListNode *l)
        {
            std::stack<int> stack;

            while (l != nullptr)
            {
                stack.push(l->val);
                l = l->next;
            }
            return stack;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            std::stack<int> stack1 = listToStack(l1);
            std::stack<int> stack2 = listToStack(l2);

            ListNode *dummyHead = new ListNode(0);        
            ListNode *current = dummyHead;

            int sum = 0;
            int carry = 0;

            while (!stack1.empty() || !stack2.empty())
            {
                sum = dummyHead->val;

                if (!stack1.empty())
                {
                    sum += stack1.top();
                    stack1.pop();
                }
                if (!stack2.empty())
                {
                    sum += stack2.top();
                    stack2.pop();
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

                dummyHead->val = sum;
                ListNode *head = new ListNode(carry, dummyHead);
                dummyHead = head;
            }         
            if (dummyHead->val == 0)
            {
                ListNode* result = dummyHead->next;
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