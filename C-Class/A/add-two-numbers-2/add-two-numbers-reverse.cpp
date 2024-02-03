
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  04:20PM 02-02-2024
//  *  Problem:                        445. Add Two Numbers II (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
// @param {Solution} self
// @param {ListNode} l1
// @param {ListNode} l2
// @return {ListNode}
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
#include <typeinfo>

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
//  Step 2: define helper function to reverse the list
//********************************************************************************************************************

        // @param {Pointer to ListNode}
        // @return {Pointer to ListNode}
        ListNode* reverseList(ListNode *l)
        {

//********************************************************************************************************************
//  Step 3: initialize previous to point to what the end of the list is pointing
//********************************************************************************************************************

            ListNode *previous = nullptr;
            ListNode *nexter;
        
            while (l != nullptr)
            {

//********************************************************************************************************************
//  Step 4: save current node's next
//********************************************************************************************************************

                nexter = l->next;

//********************************************************************************************************************
//  Step 5: set current node's next to point to what comes before it, i.e. reversing the list direction 
//********************************************************************************************************************

                l->next = previous;

//********************************************************************************************************************
//  Step 6: update previous and current for the next iteration
//********************************************************************************************************************

                previous = l;
                l = nexter;
            }

//********************************************************************************************************************
//  Step 7: return result
//********************************************************************************************************************

            return previous;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {

//********************************************************************************************************************
//  Step 8: create dummy head and current for the new list
//********************************************************************************************************************

            ListNode* dummyHead = new ListNode(0);
            ListNode* current = dummyHead;

//********************************************************************************************************************
//  Step 9: reverse the input lists for easier processing
//********************************************************************************************************************

            l1 = reverseList(l1);
            l2 = reverseList(l2);

            int carry = 0;
            int sum = 0;

//  l1      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  l2      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  current ->  (carry(0) + node x-3 x 2) ->  (carry(node x-3 x 2) + node x-2 x 2) ->  (carry(node x-2 x 2) + node x-1 x 2) -> ...
//  sum = carry
//********************************************************************************************************************
//  Step 10:    while either list remains or carry is 1
//********************************************************************************************************************

            while (l1 != nullptr || l2 != nullptr || carry == 1)
            {

//********************************************************************************************************************
//  Step 11:    carry is first added to the sum
//********************************************************************************************************************

                sum = carry;

//********************************************************************************************************************
//  Step 12:    add node value to the sum, if list 1 exists; advance the list
//********************************************************************************************************************

                if (l1 != nullptr)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }

//********************************************************************************************************************
//  Step 13:    add node value to the sum, if list 2 exists; advance the list
//********************************************************************************************************************

                if (l2 != nullptr)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }

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
//  Step 15:    add the new node to the new list; advance the list
//********************************************************************************************************************

                current->next = new ListNode(sum);
                current = current->next;
            }   
            
            // std::cout << typeid(dummyHead).name() << std::endl; //   -> 8ListNode
            // std::cout << typeid(dummyHead.next).name() << std::endl; //  -> P8ListNode
            // std::cout << typeid(current).name() << std::endl;    //  -> P8ListNode
            // std::cout << typeid(current->next).name() << std::endl;  //  ->  P8ListNode

//********************************************************************************************************************
//  Step 16:    prevent memory leak
//********************************************************************************************************************

            ListNode* result = dummyHead->next;
            delete dummyHead;

//********************************************************************************************************************
//  Step 17:    return the result, reversed
//********************************************************************************************************************

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

    ListNode *l1 = new ListNode(3, new ListNode(4, new ListNode(2)));
    ListNode *l2 = new ListNode(4, new ListNode(6, new ListNode(5)));
    
    ListNode *result;
    result = solution.addTwoNumbers(l1, l2);

    int number = 0;
    while (result != nullptr)
    {
        //  shift the entire result one significant digit to the left before adding the next node value
        number = number*10 + result->val;
        // std::cout << number << std::endl;

        result = result->next;
    } 
    
    std::cout << "Number = " << number << " \n";

    return 0;
}  