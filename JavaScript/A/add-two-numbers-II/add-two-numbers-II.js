
//
//  *  Programmer:                      Jeff C. Cheng
//  *  Last modified:                   06:59PM 03-18-2024
//  *  Problem:                         445. Add Two Numbers II (Medium)
//  *  Reference:                       https://leetcode.com/problems/add-two-numbers-ii/description/
//  Note:                               ternary operator: this.val = (val===undefined ? 0 : val)
//                                      new constructor()
//                                      integer division = Math.floor( integer1 / integer2 )
//                                      order of invocation
//
//  @func       ListNode
//  @purpose    constructor for a ListNode object
//  @param      { Integer } val
//  @param      { Pointer to ListNode } next
//  @return     { undefined }
//
//  @func       reverse
//  @purpose    reverse a linked list
//  @param      { Pointer to ListNode }
//  @return     { Pointer to ListNode }
//  
//  @func       listLength
//  @purpose    calculate the length of a list
//  @param      { Pointer to ListNode } l
//  @return     { Integer }
//
//  @func       addTwoNumbers
//  @purpose    add two numbers stored in linked lists & return the result in a linked list
//  @param      { Pointer to ListNode } l1
//  @param      { Pointer to ListNode } l2
//  @return     { Pointer to ListNode }
//
//  @func       addTwoNumbersII
//  @purpose    add two numbers stored in linked lists & return the result in a linked list
//  @param      { Pointer to ListNode } l1
//  @param      { Pointer to ListNode } l2
//  @return     { Pointer to ListNode }
//
//  @func       printInputs
//  @purpose    print the input lists
//  @param      { Pointer to ListNode } l1ptr
//  @param      { Pointer to ListNode } l2ptr
//  @return     { undefined }
//
//  @func       printResult
//  @purpose    print the result list
//  @param      { Pointer to ListNode } resultptr
//  @return     { undefined }
//
//  445. Add Two Numbers II
//  
//  You are given two non-empty linked lists representing two non-negative integers. 
//  The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
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

function ListNode(val, next) 
{
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

let reverse = function(l) 
{
    let prev = null

    while (l)
    {
        let temp = l.next;
        l.next = prev;
        prev = l;
        l = temp;
    }
    return prev;
}

let listLength = function(l)
{
    let length = 0;

    while (l)
    {
        length += 1;
        l = l.next;
    }
    return length;
}

let addTwoNumbers = function(l1, l2) 
{
    l1 = reverse(l1);
    l2 = reverse(l2);

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
    return reverse(dummyHead.next);
}

let addTwoNumbersII = function(l1, l2) 
{   
    let l1_length = listLength(l1);
    let l2_length = listLength(l2);

    let dummyHead = new ListNode();
    let head;
    let val;
    let carry = 0;

    while ((l1_length > 0) && (l2_length > 0))
    {
        val = 0;
        if (l1_length >= l2_length)
        {
            val += l1.val;
            l1 = l1.next;
            l1_length -= 1;
        }
        if (l1_length < l2_length)
        {
            val += l2.val;
            l2 = l2.next;
            l2_length -= 1;
        }

        head = new ListNode(val, dummyHead);
        dummyHead = head;
    }

    let current = dummyHead;
    dummyHead = null;

    carry = 0;
    while (current)
    {
        val = carry + current.val;
        carry = Math.floor(val / 10);
        val = val % 10;

        head = new ListNode(val, dummyHead);
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

let printInputs = (l1ptr, l2ptr, resultptr) =>
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
}

let printResult = (resultptr) =>
{
    let result = "Result List of [ ";
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

printInputs(l1, l2);
printResult(addTwoNumbers(l1, l2));
printInputs(l3, l4);
printResult(addTwoNumbers(l3, l4));
printInputs(l5, l6);
printResult(addTwoNumbers(l5, l6));

//  Example 1:
//  Input: l1 = [2,4,3], l2 = [5,6,4]
//  Output: [7,0,8]
//  Explanation: 342 + 465 = 807.    
let l7 = new ListNode(2, new ListNode(4, new ListNode(3))); 
let l8 = new ListNode(5, new ListNode(6, new ListNode(4)));

//  Example 2:
//  Input: l1 = [0], l2 = [0]
//  Output: [0]
//  Explanation:  0 + 0 = 0.
let l9 = new ListNode(0);
let l10 = new ListNode(0);

//  Example 3:
//  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//  Output: [8,9,9,9,0,0,0,1]
//  Explanation:  99999999 + 9999 = 10009998
let l11 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
let l12 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

printInputs(l7, l8);
printResult(addTwoNumbersII(l7, l8));
printInputs(l9, l10);
printResult(addTwoNumbersII(l9, l10));
printInputs(l11, l12);
printResult(addTwoNumbersII(l11, l12));
