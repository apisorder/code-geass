
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  12:26PM 1-26-2024
//  *  Problem:                        2. Add Two Numbers (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
//                                     https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  NOTE:
//                                     KNOW HOW LISTNODE IS DEFINED, ESPECIALLY ?: PART
//                                     HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
//                                     DUMMYHEAD = NEW LISTNODE(0)
// *@param {ListNode} l1
// *@param {ListNode} l2
// *@return {ListNode} 
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

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

function ListNode(val, next)
{
    this.val = (val === undefined) ? 0 : val;
    this.next = (next === undefined) ? null : next;
}

//********************************************************************************************************************
//  Step 2: define helper function to push list onto the stack, effectively reversing the list
//********************************************************************************************************************

// @param {ListNode} l
// @return {Array}
let listToStack = (l) =>
{
    //  JavaScript arrays are performant as a stack
    let stack = Array();

    while (l)
    {

//********************************************************************************************************************
//  Step 3: push list node onto the stack; advance the list
//********************************************************************************************************************

        stack.push(l.val);
        l = l.next;
    }

//********************************************************************************************************************
//  Step 4: return result
//********************************************************************************************************************

    return stack;
}

let addTwoNumbers = (l1, l2) => 
{

//********************************************************************************************************************
//  Step 5: push the lists onto the stack for easier processing
//********************************************************************************************************************

    let stack1 = listToStack(l1);    
    let stack2 = listToStack(l2);

//********************************************************************************************************************
//  Step 6: create dummy head for the new list
//********************************************************************************************************************

    let dummyHead = new ListNode(0);
    let head;

    let sum = 0;
    let carry = 0;

//  stack 1      ->  node x-1                  ->  node x-2                          ->  node x-3                          -> ...
//  stack 2      ->  node x-1                  ->  node x-2                          ->  node x-3
//  sum = dummy head value
//  head -> carry; dummy head val = (node x-1 x 2)
//  dummy head -> head   
//********************************************************************************************************************
//  Step 7: while either stack remains
//********************************************************************************************************************

    while (stack1.length != 0 || stack2.length != 0)
    {

//********************************************************************************************************************
//  Step 8: dummy head value is first added to the sum
//********************************************************************************************************************

        sum = dummyHead.val;

//********************************************************************************************************************
//  Step 9: pop node from stack 1 and add value to the sum, if stack not empty
//********************************************************************************************************************

        if (stack1.length != 0)
        {
            sum += stack1.pop();
        }

//********************************************************************************************************************
//  Step 10:    pop node from stack 2 and add value to the sum, if stacj not empty
//********************************************************************************************************************

        if (stack2.length != 0)
        {
            sum += stack2.pop();
        }

//********************************************************************************************************************
//  Step 11:    calculate node value and carry
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
//  Step 12:    assign sum to dummy head value
//********************************************************************************************************************

        dummyHead.val = sum;

//********************************************************************************************************************
//  Step 13:    add the new node to the new list; advance the list
//********************************************************************************************************************

        head = new ListNode(carry, dummyHead);
        dummyHead = head;
    }

//********************************************************************************************************************
//  Step 14:    depending on dummy head value, return the appropriate node value
//********************************************************************************************************************

    if (dummyHead.val == 0)
    { 
        return dummyHead.next;
    }
    else
    {
        return dummyHead;
    }
};

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
