
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  9:54AM 1-21-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
 *  NOTE:
 *                                  KNOW HOW LISTNODE IS DEFINED
 *                                  : VAL(0), NEXT(NULLPTR)
 *                                  KNOW HOW POINTER = (NEW) OBJECTS
 *                                  REMEMBER TO DELETE FOR MEMORY LEAK
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

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
            int carry = 0;
            
            //  allocate dummyHead on the stack
            ListNode *dummyHead = new ListNode(0);
            ListNode *current = dummyHead;

            while (carry || l1 || l2)
            {
                carry += ( l1? l1->val : 0 ) + ( l2 ? l2->val : 0 );
                current->next = new ListNode( carry % 10 );
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
            ListNode *result = dummyHead->next;
            delete dummyHead;
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
    int multiplier = 1;
    while (result != NULL)
    {
        num += result->val*multiplier;
        result = result->next;
        multiplier *= 10;
    }
    std::cout << num << std::endl;

    return 0;
}  