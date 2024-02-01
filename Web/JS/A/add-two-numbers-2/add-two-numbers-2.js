
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  4:54PM 1-26-2024
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
    this.val = (val === undefined ? 0: val);
    this.next = (next === undefined ? null: next);
}

let listLength = (l) =>
{
    let length = 0;

    while (l != null)
    {
        length += 1;
        l = l.next;
    }
    return length;
}

let addTwoNumbers = (l1, l2) => 
{
    let dummyHead = new ListNode();

    let l1_length = listLength(l1);
    let l2_length = listLength(l2);
    let sum = 0;
    let head;
    let carry = 0;

    while ((l1_length > 0) && (l2_length > 0))
    {
        sum = 0;
        if (l1_length >= l2_length)
        {
            sum += l1.val;
            l1 = l1.next;
            l1_length -= 1;
        }
        if (l1_length < l2_length)
        {
            sum += l2.val;
            l2 = l2.next;
            l2_length -= 1;
        }

        head = new ListNode(sum, dummyHead)
        dummyHead = head;
    }

    current = dummyHead;
    dummyHead = null;

    carry = 0; 
    while (current != null)
    {
        sum = current.val + carry;

        if (sum >= 10)
        {
            sum %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        head = new ListNode(sum, dummyHead);
        dummyHead = head;
        current = current.next;
    }

    if (dummyHead.val == 0)
    {
        return dummyHead.next;
    }
    else
    {
        return dummyHead;
    }
}

// Test Case:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

let l1 = new ListNode(2, new ListNode(4, new ListNode(3))); 
let l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

let result = addTwoNumbers(l1, l2);

// console.log(result)

let num = 0;    
let multiplier = 10;
    
while (result !== null)
{
    num = num*multiplier + result.val;
    result = result.next;
}
console.log(num)
