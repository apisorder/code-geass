
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  12:26PM 1-26-2024
//  *  Problem:                        2. Add Two Numbers (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
//                                     https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  NOTE:
//                                     KNOW HOW LISTNODE IS DEFINED, ESPECIALLY ?: PART
//                                     HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
//                                     DUMMYHEAD = NEW LISTNODE()
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

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

function ListNode(val, next)
{
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

var reverseList = (l) =>
{
    prev = null;

    while (l)
    {
        nexter = l.next;
        l.next = prev;
        prev = l;
        l = nexter;
    }
    return prev;
}

var addTwoNumbers = function(l1, l2) 
{
    dummyHead = new ListNode();
    current = dummyHead;
    
    carry = 0;

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    while (l1 || l2 || carry)
    {
        sum = carry;

        if (l1)
        {
            sum += l1.val;
            l1 = l1.next;
        }
        if (l2)
        {
            sum += l2.val;
            l2 = l2.next;
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

        current.next = new ListNode(sum);
        current = current.next;
    }
    return reverseList(dummyHead.next);
};

// Test Case:
// Input: l1 = [3,4,2], l2 = [4,6,5]
// Output: [8,0,7]
// Explanation: 342 + 465 = 807.

l1 = new ListNode(3, new ListNode(4, new ListNode(2))); 
l2 = new ListNode(4, new ListNode(6, new ListNode(5)));

let result = addTwoNumbers(l1, l2);

// console.log(result)

let num = 0;    
let multiplier = 10;

while (result)
{
    num = num*10 + result.val;
    result = result.next;
}

console.log(num)