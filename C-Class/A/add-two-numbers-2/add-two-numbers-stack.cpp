
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  05:53PM 02-01-2024
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
// *@param {Pointer to ListNode} l1
// *@param {Pointer to ListNode} l2
// *@return {Pointer to ListNode}
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

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

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

//********************************************************************************************************************
//  Step 2: define helper function to push list onto the stack, effectively reversing the list
//********************************************************************************************************************

        // @param {Pointer to ListNode} l
        // @return {std::stack}
        std::stack<int> listToStack(ListNode *l)
        {
            std::stack<int> stack;

            while (l != nullptr)
            {

//********************************************************************************************************************
//  Step 3: push list node onto the stack; advance the list
//********************************************************************************************************************

                stack.push(l->val);
                l = l->next;
            }

//********************************************************************************************************************
//  Step 4: return result
//********************************************************************************************************************

            return stack;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {

//********************************************************************************************************************
//  Step 5: create dummy head for the new list
//********************************************************************************************************************

            ListNode *dummyHead = new ListNode(0);

//********************************************************************************************************************
//  Step 6: push the lists onto the stack for easier processing
//********************************************************************************************************************

            std::stack<int> stack1 = listToStack(l1);
            std::stack<int> stack2 = listToStack(l2);


            int sum = 0;
            int carry = 0;
            ListNode *head;

//  stack 1      ->  node x-1                  ->  node x-2                          ->  node x-3                          -> ...
//  stack 2      ->  node x-1                  ->  node x-2                          ->  node x-3
//  sum = dummy head value
//  head -> carry; dummy head val = (node x-1 x 2)
//  dummy head -> head   
//********************************************************************************************************************
//  Step 7: while either stack remains
//********************************************************************************************************************

            while (!stack1.empty() || !stack2.empty())
            {

//********************************************************************************************************************
//  Step 8: dummy head value is first added to the sum
//********************************************************************************************************************

                sum = dummyHead->val;

//********************************************************************************************************************
//  Step 9: pop node from stack 1 and add value to the sum, if stack not empty
//********************************************************************************************************************

                if (!stack1.empty())
                {
                    sum += stack1.top();
                    stack1.pop();
                }

//********************************************************************************************************************
//  Step 10:    pop node from stack 2 and add value to the sum, if stacj not empty
//********************************************************************************************************************

                if (!stack2.empty())
                {
                    sum += stack2.top();
                    stack2.pop();
                }

//********************************************************************************************************************
//  Step 11:    calculate node value and carry
//********************************************************************************************************************

                if (sum >= 10)
                {
                    sum %= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }

//********************************************************************************************************************
//  Step 12:    assign sum to dummy head value
//********************************************************************************************************************

                dummyHead->val = sum;

//********************************************************************************************************************
//  Step 13:    add the new node to the new list; advance the list
//********************************************************************************************************************

                head = new ListNode(carry, dummyHead);
                dummyHead = head;
            }         

//********************************************************************************************************************
//  Step 14:    depending on dummy head value, return the appropriate node value
//********************************************************************************************************************

            if (dummyHead->val == 0)
            {

//********************************************************************************************************************
//  Step 15:    prevent memory leak, if needed
//********************************************************************************************************************

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

    ListNode *l1 = new ListNode(3, new ListNode(4, new ListNode(2)));
    ListNode *l2 = new ListNode(4, new ListNode(6, new ListNode(5)));
    
    ListNode *result;
    result = solution.addTwoNumbers(l1, l2);

    int number = 0;
    while (result != nullptr)
    {
        //  shift the entire number one significant digit to the left before adding the next node value
        number = number*10 + result->val;
        result = result->next;
    } 
    
    std::cout << "Number = " << number << " \n";

    return 0;
}  