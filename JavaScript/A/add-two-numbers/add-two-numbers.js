
//
//  *  Programmer:                      Jeff C. Cheng
//  *  Last modified:                   06:59PM 03-18-2024
//  *  Problem:                         2. Add Two Numbers (Medium)
//  *  Reference:                       https://leetcode.com/problems/add-two-numbers/description/
//                                      https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  Note:                               ternary operator: this.val = (val===undefined ? 0 : val)
//                                      new constructor()
//                                      integer division = Math.floor( integer1 / integer2 )
//
//  @func       ListNode
//  @purpose    constructor for a ListNode object
//  @param      { Integer } val
//  @param      { Pointer to ListNode } next
//  @return     { undefined }
//
//  @func       addTwoNumbers
//  @purpose    add two numbers stored in linked lists & return the result in a linked list
//  @param      { Pointer to ListNode } l1
//  @param      { Pointer to ListNode } l2
//  @return     { Pointer to ListNode }
//
//  @func       printResults
//  @purpose    print input lists and the result list
//  @param      { Pointer to ListNode } l1ptr
//  @param      { Pointer to ListNode } l2ptr
//  @param      { Pointer to ListNode } resultptr
//  @return     { undefined }
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
//         1 (carry)
//         342
//     +   465
//   -------------------
//         807
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
//       1
//  (7)->(0)->(8)->(3)
//
//  another edge case where the carry may be forgotten
//
//  7 + 8
//
//  carry = 1   7
//  +           8
//  _____________
//             5
//  you may forget put the 1 (carry) in the result

function ListNode(val, next) 
{
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

let addTwoNumbers = (l1, l2) => 
{
    let dummyHead = new ListNode();
    let current = dummyHead;

    let carry = 0;
    while (l1 || l2 || carry)
    {
        let val1 = l1 ? l1.val : 0;
        let val2 = l2 ? l2.val : 0;

        let val = val1 + val2 + carry;

        carry = Math.floor(val / 10);
        val = val % 10;

        current.next = new ListNode(val);
        current = current.next;

        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
    }
    return dummyHead.next;
};

let printResults = (l1ptr, l2ptr, resultptr) =>
{
    let result = "List 1 of [ ";
    while (l1ptr != null)
    {
        result += " ( " + l1ptr.val + " ) ";
        l1ptr = l1ptr.next;
    }
    result += " ] + List 2 of [ ";
    while (l2ptr != null)
    {
        result += " ( " + l2ptr.val + " ) ";
        l2ptr = l2ptr.next;
    }
    result += " ] = ";
    console.log(result);

    result = "Result List of [ ";
    while (resultptr != null)
    {
        result += " ( " + resultptr.val + " ) ";
        resultptr = resultptr.next;
    }
    result += " ] ";
    console.log(result);
    console.log();
}


//  Example 1:
//  Input: l1 = [2,4,3], l2 = [5,6,4]
//  Output: [7,0,8]
//  Explanation: 342 + 465 = 807.    
let l1 = new ListNode(2, new ListNode(4, new ListNode(3))); 
let l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

//  Example 2:
//  Input: l1 = [0], l2 = [0]
//  Output: [0]
//  Explanation:  0 + 0 = 0.
let l3 = new ListNode(0);
let l4 = new ListNode(0);

//  Example 3:
//  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//  Output: [8,9,9,9,0,0,0,1]
//  Explanation:  99999999 + 9999 = 10009998
let l5 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
let l6 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

printResults(l1, l2, addTwoNumbers(l1, l2));
printResults(l3, l4, addTwoNumbers(l3, l4));
printResults(l5, l6, addTwoNumbers(l5, l6));