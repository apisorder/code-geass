
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:56AM 1-26-2024
//  *  Problem:                        445. Add Two Numbers II (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
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
        ListNode* reverseList(ListNode *l)
        {
            ListNode *previous = nullptr;
            ListNode *nexter;
        
            while (l != nullptr)
            {
                nexter = l->next;
                l->next = previous;
                previous = l;
                l = nexter;
            }
            return previous;
        }

        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode* dummyHead = new ListNode(0);
            ListNode* current = dummyHead;

            l1 = reverseList(l1);
            l2 = reverseList(l2);

            int carry = 0;
            int sum = 0;

            while (l1 != nullptr || l2 != nullptr || carry == 1)
            {
                sum = carry;

                if (l1 != nullptr)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr)
                {
                    sum += l2->val;
                    l2 = l2->next;
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

                current->next = new ListNode(sum);
                current = current->next;
            }   
            
            // std::cout << typeid(dummyHead).name() << std::endl; //   -> 8ListNode
            // std::cout << typeid(dummyHead.next).name() << std::endl; //  -> P8ListNode
            // std::cout << typeid(current).name() << std::endl;    //  -> P8ListNode
            // std::cout << typeid(current->next).name() << std::endl;  //  ->  P8ListNode

            ListNode* result = dummyHead->next;
            delete dummyHead;
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