
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:58AM 1-26-2024
//  *  Problem:                        445. Add Two Numbers II (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
//  NOTE:                              
//                                     MOST IMPORTANT 1    HOW TO CALCULATE CARRY
//                                     MOST IMPORTANT 2    HOW TO INCLUDE CARRY IN CALCULATION
                                    
//                                     during first pass, sum = 0
//                                     head = ListNode( sum, dummyHead )
//                                     dummyHead = head

//                                     during second pass, sum = 0 also
//                                     then sum = current->val + carry

//                                     head = ListNode( sum, dummyHead )
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