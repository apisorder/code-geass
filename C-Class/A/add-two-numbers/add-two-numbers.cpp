
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  8:08AM 02-01-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
 *  NOTE:
 *                                  KNOW HOW LISTNODE IS DEFINED
 *                                  : VAL(0), NEXT(NULLPTR)
 *                                  KNOW HOW POINTER = (NEW) OBJECTS
 *                                  REMEMBER TO DELETE FOR MEMORY LEAK
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

// 2. Add Two Numbers
// Solved
// Medium
// Topics
// Companies

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, 
// except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Accepted
// 4.2M
// Submissions
// 10.1M
// Acceptance Rate
// 42.0%

#include <iostream>

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {

//********************************************************************************************************************
//  Step 2: create dummy head and current for the new list
//********************************************************************************************************************
            
            ListNode *dummyHead = new ListNode(0);
            ListNode *current = dummyHead;

            int sum = 0;
            int carry = 0;


//  l1      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  l2      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  current ->  (carry(0) + node 1 x 2) ->  (carry(node1 x 2) + node 2 x 2) ->  (carry(node2 x 2) + node 3 x 2) -> ...
//  sum = carry
//********************************************************************************************************************
//  Step 3: while either list remains or carry is 1
//********************************************************************************************************************
            
            while (carry || l1 || l2)
            {

//********************************************************************************************************************
//  Step 4: carry is first added to the sum
//********************************************************************************************************************
            
                sum = carry;

//********************************************************************************************************************
//  Step 5: add node value to the sum, if list 1 exists; advance the list
//********************************************************************************************************************
            
                if (l1)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }

//********************************************************************************************************************
//  Step 6: add node value to the sum, if list 2 exists; advance the list
//********************************************************************************************************************
                
                if (l2)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }

//********************************************************************************************************************
//  Step 7: calculate node value and carry
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
//  Step 8: add the new node to the new list; advance the list
//********************************************************************************************************************
                
                current->next = new ListNode(sum);
                current = current->next;
            }

//********************************************************************************************************************
//  Step 9: prevent memory leak
//********************************************************************************************************************
            
            ListNode *result = dummyHead->next;
            delete dummyHead;

//********************************************************************************************************************
//  Step 10:    return the result
//********************************************************************************************************************
            
            return result;
        }
};

int main()
{
    // Test Case:
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.

    Solution solution;
    
    ListNode l1 = ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode l2 = ListNode(5, new ListNode(6, new ListNode(4)));
    
    ListNode *result;
    result = solution.addTwoNumbers(&l1, &l2);
    
    int num = 0;

//  multiplier is used to place the sum of the two nodes at the correct significant place
    int multiplier = 1;
    while (result != NULL)
    {
        num += result->val*multiplier;
        // std::cout << num << std::endl;

        result = result->next;
        multiplier *= 10;
    }
    std::cout << num << std::endl;

    return 0;
}  