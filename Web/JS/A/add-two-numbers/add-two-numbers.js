
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  8:50PM 02-01-2024
//  *  Problem:                        2. Add Two Numbers (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
//                                     https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  NOTE:
//                                     KNOW HOW LISTNODE IS DEFINED, ESPECIALLY ?: PART
//                                     HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
// @param {ListNode} l1
// @param {ListNode} l2
// @return {ListNode}
//

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

function ListNode(val, next) 
{
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

let addTwoNumbers = (l1, l2) => 
{

//********************************************************************************************************************
//  Step 2: create dummy head and current for the new list
//********************************************************************************************************************

    let dummyHead = new ListNode(0);
    let current = dummyHead;

    let carry = 0;
    let sum = 0;

//  l1      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  l2      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  current ->  (carry(0) + node 1 x 2) ->  (carry(node1 x 2) + node 2 x 2) ->  (carry(node2 x 2) + node 3 x 3) -> ...   
//  sum = carry
//********************************************************************************************************************
//  Step 3: while either list remains or carry is 1
//********************************************************************************************************************

    while (l1 !== null || l2 !== null || carry == 1)
    {

//********************************************************************************************************************
//  Step 4: carry is first added to the sum
//********************************************************************************************************************

        sum = carry;

//********************************************************************************************************************
//  Step 5: add node value to the sum, if list 1 exists; advance the list
//********************************************************************************************************************

        if (l1 !== null)
        {
            sum += l1.val;
            l1 = l1.next;
        }

//********************************************************************************************************************
//  Step 6: add node value to the sum, if list 2 exists; advance the list
//********************************************************************************************************************

        if (l2 !== null)
        {
            sum += l2.val;
            l2 = l2.next;
        }

//********************************************************************************************************************
//  Step 7: calculate node value and carry
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
//  Step 8: add the new node to the new list; advance the list
//********************************************************************************************************************

        current.next = new ListNode(sum);
        current = current.next;
    }

//********************************************************************************************************************
//  Step 9: return the result
//********************************************************************************************************************

    return dummyHead.next;
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
let multiplier = 1;

// multiplier is used to place the sum of the two nodes at the correct significant placewhile (result !== null)
while (result)
{
    num += result.val*multiplier;
    result = result.next;
    multiplier *= 10;
}
console.log(num)