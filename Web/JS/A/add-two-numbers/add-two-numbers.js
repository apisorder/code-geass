
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  8:42PM 1-22-2024
//  *  Problem:                        2. Add Two Numbers (Medium)
//  *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
//                                     https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
//  NOTE:
//                                     KNOW HOW LISTNODE IS DEFINED
//                                     HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
//

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

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

var addTwoNumbers = function(l1, l2) 
{
    dummyHead = new ListNode(0);
    current = dummyHead;

    carry = 0;

    while (l1 !== null || l2 !== null || carry == 1)
    {
        sum = carry;

        if (l1 !== null)
        {
            sum += l1.val;
            l1 = l1.next;
        }
        if (l2 !== null)
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
    return dummyHead.next;
};