
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  04:27PM 03-18-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
 * 
 *  @func addTwoNumbers                                    
 *  @param {Solution} self
 *  @param {Pointer to ListNode} l1
 *  @param {Pointer to ListNode} l2
 *  @return {Pointer to ListNode}
 *
 *  @func printResults
 *  @param {Solution} self
 *  @param {Pointer to ListNode} l1ptr
 *  @param {Pointer to ListNode} l2ptr
 *  @param {Pointer to ListNode} resultptr
 *  @return {None}
*/
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
// -------------------
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

class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution 
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        ListNode dummyHead = new ListNode();
        ListNode current = dummyHead;

        int carry = 0;
        //  convert to boolean*
        while ( (l1 != null) || (l2 != null) || (carry == 1) )
        {
            int val1 = (l1 != null) ? l1.val : 0;   
            int val2 = (l2 != null) ? l2.val : 0;

            int val = val1 + val2 + carry;

            carry = val / 10;            
            val = val % 10;

            current.next = new ListNode(val);
            current = current.next;

            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;
        }
        return dummyHead.next;
    }

    public void printResults(ListNode l1ptr, ListNode l2ptr, ListNode resultptr)
    {
        System.out.print("List 1 of [ ");
        while (l1ptr != null)
        {
            System.out.print(" ( " + l1ptr.val + " ) ");
            l1ptr = l1ptr.next;
        }
        System.out.print(" ] + ");
        
        System.out.print("List 2 of [ ");
        while (l2ptr != null)
        {
            System.out.print(" ( " + l2ptr.val + " ) ");
            l2ptr = l2ptr.next;
        }
        System.out.println(" ] = ");

        System.out.print("Result List of [ ");
        while (resultptr != null)
        {
            System.out.print(" ( " + resultptr.val + " ) ");
            resultptr = resultptr.next;
        }
        System.out.println(" ] ");
        System.out.println();
    }
}

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();       

        // Example 1:
        // Input: l1 = [2,4,3], l2 = [5,6,4]
        // Output: [7,0,8]
        // Explanation: 342 + 465 = 807.    
        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

        //  Example 2:
        //  Input: l1 = [0], l2 = [0]
        //  Output: [0]
        //  Explanation:  0 + 0 = 0.
        ListNode l3 = new ListNode(0);
        ListNode l4 = new ListNode(0);

        //  Example 3:
        //  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
        //  Output: [8,9,9,9,0,0,0,1]
        //  Explanation:  99999999 + 9999 = 10009998
        ListNode l5 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
        ListNode l6 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

        solution.printResults(l1, l2, solution.addTwoNumbers(l1, l2));
        solution.printResults(l3, l4, solution.addTwoNumbers(l3, l4));
        solution.printResults(l5, l6, solution.addTwoNumbers(l5, l6));    
    }
}