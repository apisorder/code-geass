
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  07:36AM 03-21-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 *  Note:                           initializer list func() : var(), var() {}
 *                                  new constructor()
 *                                  order of invocation
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
 *  @func       reverse
 *  @purpose    reverse a linked list
 *  @param      { Pointer to ListNode }
 *  @return     { Pointer to ListNode } 
 * 
 *  @func       listLength
 *  @purpose    calculate the length of a list
 *  @param      { Pointer to ListNode }
 *  @return     { Integer } 
 *
 *  @func       addTwoNumbers                                    
 *  @purpose    add two numbers stored in linked lists & return the result in a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1
 *  @param      { Pointer to ListNode } l2
 *  @return     { Pointer to ListNode }
 *
 *  @func       addTwoNumbersII                                    
 *  @purpose    add two numbers stored in linked lists & return the result in a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1
 *  @param      { Pointer to ListNode } l2
 *  @return     { Pointer to ListNode }
 
 *  @func       printInputs
 *  @purpose    print the two input lists
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1ptr
 *  @param      { Pointer to ListNode } l2ptr
 *  @return     { None }
 * 
 *  @func       printResult
 *  @purpose    print the result list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } resultptr
 *  @return     { None }
 */
//
//  445. Add Two Numbers II
//  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and 
//  each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
//  Example 1:
//  Input: l1 = [7,2,4,3], l2 = [5,6,4]
//  Output: [7,8,0,7]
//
//  Example 2:
//  Input: l1 = [2,4,3], l2 = [5,6,4]
//  Output: [8,0,7]
//
//  Example 3:
//  Input: l1 = [0], l2 = [0]
//  Output: [0]
//
//  Constraints:
//  The number of nodes in each linked list is in the range [1, 100].
//  0 <= Node.val <= 9
//  It is guaranteed that the list represents a number that does not have leading zeros.
// 
//  Follow up: Could you solve it without reversing the input lists?

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
        ListNode* reverse(ListNode* l)
        {
            ListNode* prev = nullptr;

            while (l)
            {
                ListNode* temp = l->next;
                l->next = prev;
                prev = l;
                l = temp;
            }
            return prev;
        }

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

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *dummyHead = new ListNode();
            ListNode *current = dummyHead;

            l1 = reverse(l1);
            l2 = reverse(l2);

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
            return reverse(dummyHead->next);
        }

        ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) 
        {
            int l1_length = listLength(l1);
            int l2_length = listLength(l2);

            ListNode* dummyHead = new ListNode();    

            while ((l1_length > 0) && (l2_length > 0))
            {
                int val = 0;
                if (l1_length >= l2_length)
                {
                    val += l1->val;
                    l1 = l1->next;
                    l1_length -= 1;
                }
                if (l1_length < l2_length)
                {
                    val += l2->val;
                    l2 = l2->next;
                    l2_length -= 1;
                }

                ListNode *head = new ListNode(val, dummyHead);
                dummyHead = head;
            }

            ListNode* current = dummyHead;
            dummyHead = nullptr;

            int carry = 0;
            int sum = 0;
            while (current)
            {
                sum = current->val + carry;

                carry = sum / 10;
                sum = sum % 10;

                ListNode* head = new ListNode(sum, dummyHead);
                dummyHead = head;

                current = current->next;
            }

            if (dummyHead->val == 0)
            {
                return dummyHead->next;
            }
            else
            {
                return dummyHead;
            }
        }
    
        void printInputs(ListNode *l1ptr, ListNode *l2ptr)
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
        }

        void printResult(ListNode *resultptr)
        {
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

    //  Example 1:
    //  Input: l1 = [7,2,4,3], l2 = [5,6,4]
    //  Output: [7,8,0,7]
    ListNode l1 = ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode l2 = ListNode(5, new ListNode(6, new ListNode(4)));
    
    //  Example 2:
    //  Input: l1 = [2,4,3], l2 = [5,6,4]
    //  Output: [8,0,7]
    ListNode l3 = ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode l4 = ListNode(5, new ListNode(6, new ListNode(4)));

    //  Example 3:
    //  Input: l1 = [0], l2 = [0]
    //  Output: [0]
    ListNode l5 = ListNode(0);
    ListNode l6 = ListNode(0);

    solution.printInputs(&l1, &l2);
    solution.printResult(solution.addTwoNumbers(&l1, &l2));
    solution.printInputs(&l3, &l4);
    solution.printResult(solution.addTwoNumbers(&l3, &l4));
    solution.printInputs(&l5, &l6);
    solution.printResult(solution.addTwoNumbers(&l5, &l6));

    //  Example 1:
    //  Input: l1 = [7,2,4,3], l2 = [5,6,4]
    //  Output: [7,8,0,7]
    ListNode l7 = ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode l8 = ListNode(5, new ListNode(6, new ListNode(4)));
    
    //  Example 2:
    //  Input: l1 = [2,4,3], l2 = [5,6,4]
    //  Output: [8,0,7]
    ListNode l9 = ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode l10 = ListNode(5, new ListNode(6, new ListNode(4)));

    //  Example 3:
    //  Input: l1 = [0], l2 = [0]
    //  Output: [0]
    ListNode l11 = ListNode(0);
    ListNode l12 = ListNode(0);

    solution.printInputs(&l7, &l8);
    solution.printResult(solution.addTwoNumbersII(&l7, &l8));
    solution.printInputs(&l9, &l10);
    solution.printResult(solution.addTwoNumbersII(&l9, &l10));
    solution.printInputs(&l11, &l12);
    solution.printResult(solution.addTwoNumbersII(&l11, &l12));

    return 0;
}  