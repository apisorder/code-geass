
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  06:25PM 02-01-2024
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
// @param {Pointer to ListNode} l1 
// @param {Pointer to ListNode} l2
// @return {Pointer to ListNode}
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

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

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

//********************************************************************************************************************
//  Step 2: define helper function to calculate list length
//********************************************************************************************************************

        // @param {Pointer to ListNode}
        // @return {Integer}
        int listLength(ListNode *l)
        {
            int length = 0;

            while (l)
            {

//********************************************************************************************************************
//  Step 3: calculate the length of the list for each list node; advance the list
//********************************************************************************************************************

                length += 1;
                l = l->next;
            }

//********************************************************************************************************************
//  Step 4: return the result
//********************************************************************************************************************

            return length;
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {

//********************************************************************************************************************
//  Step 5: create dummy head for the new list
//********************************************************************************************************************

            ListNode *dummyHead = new ListNode(0);
            ListNode *head;
            ListNode *current;

//********************************************************************************************************************
//  Step 6: calculate list length for both lists
//********************************************************************************************************************

            int l1_length = listLength(l1);
            int l2_length = listLength(l2);

            int sum = 0;

//  dummy head -> node from the longer/equal-length list -> ...
//  head -> (sum, dummy head)
//  dummy head -> head
//  sum = 0
//********************************************************************************************************************
//  Step 7: while either list still remains; list length > 0
//********************************************************************************************************************

            while ((l1_length > 0) && (l2_length > 0))
            {
                sum = 0;

//********************************************************************************************************************
//  Step 8: if list 1 is longer, add node value to the sum; advance the list; decrement list length
//********************************************************************************************************************

                if (l1_length >= l2_length)
                {
                    sum += l1->val;
                    l1 = l1->next;
                    l1_length -= 1;
                }

//********************************************************************************************************************
//  Step 9: however, if list 2 is longer, add node value to the sum; advance the list; decrement list length 
//********************************************************************************************************************

                if (l1_length < l2_length)
                {
                    sum += l2->val;
                    l2 = l2->next;
                    l2_length -= 1;
                }

//********************************************************************************************************************
//  Step 10:    head contains sum, and points to dummy head; then point dummy head to head; grow list in reverse
//********************************************************************************************************************

                head = new ListNode(sum, dummyHead);
                dummyHead = head;
            }       

//********************************************************************************************************************
//  Step 11:    current to point to dummyHead; point dummy head to point to the new list, i.e. nullptr
//********************************************************************************************************************

            current = dummyHead;
            dummyHead = nullptr;

            int carry = 0;

//********************************************************************************************************************
//  Step 12:    while the list remains
//********************************************************************************************************************

            //  the last current node will contain the value of 0, which will handle any last carry
            //  i.e. if the last two nodes both contain the value of 9
            //  current->val = 18
            //  carry = 0
            //  sum = 18
            //  current->val = 0
            //  carry = 1
            //  sum = 1
            //  Number = 18 
            while (current != nullptr)
            {

//********************************************************************************************************************
//  Step 13:    add both node value and carry to the sum
//********************************************************************************************************************

                sum = current->val + carry;
                // std::cout << "current->val = " << current->val << std::endl;
                // std::cout << "carry = " << carry << std::endl;  
                // std::cout << "sum = " << sum << std::endl;

//********************************************************************************************************************
//  Step 14:    calculate node value and carry
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
//  Step 15:    head contains sum, and points to dummy head; then point dummy head to head; grow list in reverse
//********************************************************************************************************************

                head = new ListNode(sum, dummyHead);
                dummyHead = head;

//********************************************************************************************************************
//  Step 16:    advance list
//********************************************************************************************************************

                current = current->next;
            }

//********************************************************************************************************************
//  Step 17:    return the result
//********************************************************************************************************************

            if (dummyHead->val == 0)
            {

//********************************************************************************************************************
//  Step 18:    prevent memory leak, if needed
//********************************************************************************************************************

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

    // ListNode *l1 = new ListNode(3, new ListNode(4, new ListNode(2)));
    // ListNode *l2 = new ListNode(4, new ListNode(6, new ListNode(5)));

    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);

    ListNode *result;

    result = solution.addTwoNumbers(l1, l2);

    int number = 0;
    while (result != nullptr)
    {
        //  advance number one significant digit to the left before adding the next node value
        number = number*10 + result->val;
        result = result->next;
    } 
    
    std::cout << "Number = " << number << " \n";

    return 0;

}