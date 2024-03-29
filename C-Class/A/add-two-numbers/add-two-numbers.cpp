
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:41AM 03-18-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
 *  Note:                           initializer list func() : var(), var() {}
 *                                  new constructor()
 *
 *  @func       ListNode
 *  @purpose    constructor for ListNode structure
 *  @param      { None }
 *  @return     { None }
 *
 *  @func       ListNode
 *  @purpose    constructor for ListNode structure
 *  @param      { Integer } x
 *  @return     { None }
 *
 *  @func       ListNode
 *  @purpose    constructor for ListNode structure
 *  @param      { Integer } x
 *  @param      { Pointer to ListNode } next
 *  @return     { None }
 *
 *  @func       addTwoNumbers                                    
 *  @purpose    add two numbers stored in linked lists & return the result in a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1
 *  @param      { Pointer to ListNode } l2
 *  @return     { Pointer to ListNode }
 *
 *  @func       printResults
 *  @purpose    print input lists and the result list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1ptr
 *  @param      { Pointer to ListNode } l2ptr
 *  @param      { Pointer to ListNode } resultptr
 *  @return     { None }
 */
//
//  2. Add Two Numbers
//
//  You are given two non-empty linked lists representing two non-negative integers. 
//  The digits are stored in reverse order, and each of their nodes contains a single digit. 
//  Add the two numbers and return the sum as a linked list.
//
//  You may assume the two numbers do not contain any leading zero, 
//  except the number 0 itself.
//
//  Example 1:
//  Input: l1 = [2,4,3], l2 = [5,6,4]
//  Output: [7,0,8]
//  Explanation: 342 + 465 = 807.
//
//  Example 2:
//  Input: l1 = [0], l2 = [0]
//  Output: [0]
//
//  Example 3:
//  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//  Output: [8,9,9,9,0,0,0,1]
//
//  Constraints:
//
//  The number of nodes in each linked list is in the range [1, 100].
//  0 <= Node.val <= 9
//  It is guaranteed that the list represents a number that does not have leading zeros.
//
//  non-empty
//  non-negative integers
//  reverse order
//
//  NOTE:
//  https://www.youtube.com/watch?v=wgFPrzTjm7s
// 
//  Input:  ( 2 -> 4 -> 3 ) + ( 5 -> 6 -> 4 )
//  Output: 7 -> 0 -> 8
//  Explanation:    342 + 465 = 807
//
//          1 (carry)
//          342
//      +   465
// -------------------
//          807
//  a lot of edge cases
// 
//  Edge Cases:
//
//  what if the two linked lists we are adding are of different sizes
//  3342 + 465
//
//  start at the 1's the place
//  then the 10's place
//  etc.
//
//  edge case where the numbers are of different length
//
//  (5)->(6)->(4)->(X) if X assumed 0
//  (2)->(4)->(3)->(3)
//        1
//  (7)->(0)->(8)->(3)
//
//  another edge case where the carry may be forgotten
//
//  7 + 8
//
//  carry = 1   7
//  +           8
//  _____________
//              5
//  you may forget put the 1 (carry) in the result

#include <iostream>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) 
    {
    }
    ListNode(int x) : val(x), next(nullptr) 
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next) 
    {
    }
};

class Solution 
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode* dummyHead =  new ListNode();
            ListNode* current = dummyHead;

            int carry = 0;
            while (l1 || l2 || carry)
            {
                int val1 = l1 ? l1->val : 0;
                int val2 = l2 ? l2->val : 0;

                int val = val1 + val2 + carry;

                carry = val / 10;
                val = val % 10;

                current->next = new ListNode(val);
                current = current->next;

                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }
            return dummyHead->next;
        }

        void printResults(ListNode *l1ptr, ListNode *l2ptr, ListNode *resultptr)
        {
            std::cout << "List 1 of [ ";
            while (l1ptr != nullptr)
            {
                std::cout << " ( " << l1ptr->val << " ) ";
                l1ptr = l1ptr->next;
            }
            std::cout << " ] + ";
            
            std::cout << "List 2 of [ ";
            while (l2ptr != nullptr)
            {
                std::cout << " ( " << l2ptr->val << " ) ";
                l2ptr = l2ptr->next;
            }
            std::cout << " ] = " << std::endl;

            std::cout << "Result List of [ ";
            while (resultptr != nullptr)
            {
                std::cout << " ( " << resultptr->val << " ) ";
                resultptr = resultptr->next;
            }
            std::cout << " ] " << std::endl << std::endl;
        }
};

int main()
{
    Solution solution;

    // Example 1:
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.    
    ListNode l1 = ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode l2 = ListNode(5, new ListNode(6, new ListNode(4)));

    //  Example 2:
    //  Input: l1 = [0], l2 = [0]
    //  Output: [0]
    //  Explanation:  0 + 0 = 0.
    ListNode l3 = ListNode(0);
    ListNode l4 = ListNode(0);

    //  Example 3:
    //  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    //  Output: [8,9,9,9,0,0,0,1]
    //  Explanation:  99999999 + 9999 = 10009998
    ListNode l5 = ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode l6 = ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    solution.printResults(&l1, &l2, solution.addTwoNumbers(&l1, &l2));
    solution.printResults(&l3, &l4, solution.addTwoNumbers(&l3, &l4));
    solution.printResults(&l5, &l6, solution.addTwoNumbers(&l5, &l6));

    return 0;
}  