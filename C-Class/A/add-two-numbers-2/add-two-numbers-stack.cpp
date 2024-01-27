
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:50AM 1-26-2024
//  *  Problem:                        445. Add Two Numbers II (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
//  NOTE:                              
//                                     MOST IMPORTANT 1    HOW TO CALCULATE CARRY
//                                     MOST IMPORTANT 2    HOW TO INCLUDE CARRY IN CALCULATION

//                                     inside while loop, init sum to current.val (carry from before)
//                                         i.e. sum = dummyhead->val

//                                     and therefore must...
                                    
//                                     dummyHead->val = sum
//                                     head = ListNode( carry, dummyHead )
//  NOTE:                                  HEAD = LISTNODE( CARRY, LISTNODE(SUM)) IS WRONG
//                                     dummyHead = head
//

// 445. Add Two Numbers II
// Solved
// Medium
// Topics
// Companies
// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.
 

// Follow up: Could you solve it without reversing the input lists?

// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Accepted
// 458.9K
// Submissions
// 751.4K
// Acceptance Rate
// 61.1%

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