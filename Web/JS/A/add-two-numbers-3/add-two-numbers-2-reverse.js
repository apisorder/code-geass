
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  04:29PM 02-02-2024
//  *  Problem:                        2. Add Two Numbers (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
//                                     https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  NOTE:
//                                     KNOW HOW LISTNODE IS DEFINED, ESPECIALLY ?: PART
//                                     HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
//                                     DUMMYHEAD = NEW LISTNODE()
// @param {ListNode} l1
// @param {ListNode} l2
// @return {ListNode}

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

//********************************************************************************************************************
//  Step 1: create list node
//********************************************************************************************************************

function ListNode(val, next)
{
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

//********************************************************************************************************************
//  Step 2: define helper function to reverse the list for easier processing
//********************************************************************************************************************

// @param {ListNode} l
// @return {ListNode}
let reverseList = (l) =>
{

//********************************************************************************************************************
//  Step 3: initialize previous to point to what the end of the list is pointing
//********************************************************************************************************************

    let prev = null;
    let nexter;

    while (l)
    {

//********************************************************************************************************************
//  Step 4: save current node's next
//********************************************************************************************************************

        nexter = l.next;

//********************************************************************************************************************
//  Step 5: set current node's next to point to what comes before it, i.e. reversing the list direction 
//********************************************************************************************************************

        l.next = prev;

//********************************************************************************************************************
//  Step 6: update previous and current for the next iteration
//********************************************************************************************************************

        prev = l;
        l = nexter;
    }

//********************************************************************************************************************
//  Step 7: return result
//********************************************************************************************************************

    return prev;
}

let addTwoNumbers = (l1, l2) => 
{

//********************************************************************************************************************
//  Step 8: create dummy head and current for the new list
//********************************************************************************************************************

    let dummyHead = new ListNode();
    let current = dummyHead;
    
    let carry = 0;
    let sum = 0;

    //********************************************************************************************************************
//  Step 9: reverse the input list for easier processing
//********************************************************************************************************************

    l1 = reverseList(l1);
    l2 = reverseList(l2);

//  l1      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  l2      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  current ->  (carry(0) + node x-3 x 2) ->  (carry(node x-3 x 2) + node x-2 x 2) ->  (carry(node x-2 x 2) + node x-1 x 2) -> ...
//  sum = carry
//********************************************************************************************************************
//  Step 10:    while either list remains or carry is 1
//********************************************************************************************************************
    
    while (l1 || l2 || carry)
    {

//********************************************************************************************************************
//  Step 11:    carry is first added to the sum
//********************************************************************************************************************

        sum = carry;

//********************************************************************************************************************
//  Step 12:    add node value to the sum, if list 1 exists; advance the list
//********************************************************************************************************************

        if (l1)
        {
            sum += l1.val;
            l1 = l1.next;
        }

//********************************************************************************************************************
//  Step 13:    add node value to the sum, if list 2 exists; advance the list
//********************************************************************************************************************

        if (l2)
        {
            sum += l2.val;
            l2 = l2.next;
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

        current.next = new ListNode(sum);
        current = current.next;
    }

//********************************************************************************************************************
//  Step 16:    return the reversed list
//********************************************************************************************************************

    return reverseList(dummyHead.next);
};

// Test Case:
// Input: l1 = [3,4,2], l2 = [4,6,5]
// Output: [8,0,7]
// Explanation: 342 + 465 = 807.

let l1 = new ListNode(3, new ListNode(4, new ListNode(2))); 
let l2 = new ListNode(4, new ListNode(6, new ListNode(5)));

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