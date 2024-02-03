
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  05:03PM 02-02-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
*/

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

import java.util.Stack;

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

class ListNode
{
    int val;
    ListNode next;

    ListNode(){}
    ListNode(int val){ this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
};

class Solution
{

//********************************************************************************************************************
//  Step 2: define helper function to calculate list length
//********************************************************************************************************************

    // @param {ListNode} l
    // @return {Integer}
    int listLength(ListNode l)
    {
        int length = 0;

//********************************************************************************************************************
//  Step 3: increment list length while list node exists; advance the list
//********************************************************************************************************************

        while (l != null)
        {
            length += 1;
            l = l.next;
        }

//********************************************************************************************************************
//  Step 4: return the result
//********************************************************************************************************************

        return length;
    }

//********************************************************************************************************************
//  Step 2 ALT: define helper function to push list nodes onto the stack
//********************************************************************************************************************

    // @param {ListNode} l
    // @return {Stack<Integer> stack}
    Stack<Integer> listToStack(ListNode l)
    {
        Stack<Integer> stack = new Stack<Integer>();

//********************************************************************************************************************
//  Step 3 ALT: while the list exist, push list node ont the stack; advance the list
//********************************************************************************************************************

        while (l != null)
        {
            stack.push(l.val);
            l = l.next;
        }

//********************************************************************************************************************
//  Step 4 ALT: return the result
//********************************************************************************************************************

        return stack;
    }

//********************************************************************************************************************
//  Step 2 ALT: define helper function to reverse the list for easier processing
//********************************************************************************************************************

    // @param {ListNode} l
    // @return {ListNode}
    ListNode reverseList(ListNode l)
    {

//********************************************************************************************************************
//  Step 3 ALT: initialize previous to point to what the end of the list is pointing
//********************************************************************************************************************

        ListNode prev = null;
        ListNode nexter;

        while (l != null)
        {
            nexter = l.next;
            l.next = prev;
            prev = l;
            l = nexter;
        }

//********************************************************************************************************************
//  Step 4: return the result
//********************************************************************************************************************

        return prev;
    }

    ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {

//********************************************************************************************************************
//  Step 5: calculate list length for deciding which list node to add to the sum first
//********************************************************************************************************************

        int l1_length = listLength(l1);
        int l2_length = listLength(l2);

//********************************************************************************************************************
//  Step 6: create dummy head for the new list
//********************************************************************************************************************
        
        ListNode dummyHead = new ListNode(0);
        int sum = 0;
        ListNode head;
        ListNode current;

//  stack 1      ->  node x-1                  ->  node x-2                          ->  node x-3                          -> ...
//  stack 2      ->  node x-1                  ->  node x-2                          ->  node x-3
//  sum = dummy head value
//  head -> carry; dummy head val = (node x-1 x 2)
//  dummy head -> head   
//********************************************************************************************************************
//  Step 7: while either stack remains
//********************************************************************************************************************

        while ((l1_length > 0) && (l2_length > 0))
        {
            sum = 0;

//********************************************************************************************************************
//  Step 8: add to the sum node value from the longer (or equal-length ) list; advance the list; decrement list length
//********************************************************************************************************************

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

//********************************************************************************************************************
//  Step 9: let head value equals sum; next equals dummy head; then let dumm head points to head; grow list backwards
//********************************************************************************************************************

            head = new ListNode(sum, dummyHead);
            dummyHead = head;
        }

//********************************************************************************************************************
//  Step 10:    current equals dummy head; dummy head starts the new list
//********************************************************************************************************************

        current = dummyHead;
        dummyHead = null;
        
        int carry = 0;

//********************************************************************************************************************
//  Step 11:    while the first combined list exists
//********************************************************************************************************************

        //  the last current node will contain the value of 0, which will handle any last carry
        //  i.e. if the last two nodes both contain the value of 9
        //  current->val = 18
        //  carry = 0
        //  sum = 18
        //  current->val = 0
        //  carry = 1
        //  sum = 1
        //  Number = 18 
        while (current != null)
        {

//********************************************************************************************************************
//  Step 12:    add the node value and any carry to the sum
//********************************************************************************************************************

            sum = current.val + carry; 
            
//********************************************************************************************************************
//  Step 13:    calculate node value and carry
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
//  Step 14:    repeat step 9
//********************************************************************************************************************

            head = new ListNode(sum, dummyHead);
            dummyHead = head;

            current = current.next;
        }

//********************************************************************************************************************
//  Step 15:    return the appropriate result
//********************************************************************************************************************

        if (dummyHead.val == 0)
        {
            return dummyHead.next;
        }
        else
        {
            return dummyHead;
        }
    }

    ListNode addTwoNumbersStack(ListNode l1, ListNode l2)
    {

//********************************************************************************************************************
//  Step 5 ALT: push the lists onto the stack so the nodes are natural order
//********************************************************************************************************************

        Stack<Integer> stack1 = listToStack(l1);
        Stack<Integer> stack2 = listToStack(l2);

//********************************************************************************************************************
//  Step 6 ALT: create dummy head for the new list
//********************************************************************************************************************

        ListNode dummyHead = new ListNode(0);
        ListNode head;

        int sum = 0;
        int carry = 0 ;

//  stack 1      ->  node x-1                  ->  node x-2                          ->  node x-3                          -> ...
//  stack 2      ->  node x-1                  ->  node x-2                          ->  node x-3
//  sum = dummy head value
//  head -> carry; dummy head val = (node x-1 x 2)
//  dummy head -> head   
//********************************************************************************************************************
//  Step 7 ALT: while either stack remains
//********************************************************************************************************************

        while (!stack1.empty() || !stack2.empty())
        {
            sum = dummyHead.val;

//********************************************************************************************************************
//  Step 8 ALT: while either stack is non-empty, add the popped node value to the sum
//********************************************************************************************************************

            if (!stack1.empty())
            {
                sum += stack1.pop();
            }
            if (!stack2.empty())
            {
                sum += stack2.pop();
            }

//********************************************************************************************************************
//  Step 9 ALT: calculate node value and carry
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
//  Step 10 ALT:    dummy head value equals sum; next points to dummy head; dummy head points to head; list backwards
//********************************************************************************************************************

            dummyHead.val = sum;
            head = new ListNode(carry, dummyHead);
            dummyHead = head;
        }

//********************************************************************************************************************
//  Step 11 ALT:    return the approrpriate result
//********************************************************************************************************************

        if (dummyHead.val == 0)
        {
            return dummyHead.next;
        }
        else
        {
            return dummyHead;
        }
    }

    ListNode addTwoNumbersReverse(ListNode l1, ListNode l2)
    {

//********************************************************************************************************************
//  Step 5 ALT2: reverse the input lists for easier processing
//********************************************************************************************************************

        l1 = reverseList(l1);
        l2 = reverseList(l2);

//********************************************************************************************************************
//  Step 6 ALT2: create dummy head and current for the new list
//********************************************************************************************************************

        ListNode dummyHead = new ListNode();
        ListNode current = dummyHead;

        int carry = 0;
        int sum = 0;

//  l1      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  l2      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
//  current ->  (carry(0) + node x-3 x 2) ->  (carry(node x-3 x 2) + node x-2 x 2) ->  (carry(node x-2 x 2) + node x-1 x 2) -> ...
//  sum = carry
//********************************************************************************************************************
//  Step 7 ALT2: while either list remains or that the carry is 1; that we can still add node value to the new list 
//********************************************************************************************************************

        while ((l1 != null) || (l2 != null) || (carry == 1))
        {
            sum = carry;

//********************************************************************************************************************
//  Step 8 ALT2: add node value from any non-empty list to the sum; advance the list
//********************************************************************************************************************

            if (l1 != null)
            {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null)
            {
                sum += l2.val;
                l2 = l2.next;
            }

//********************************************************************************************************************
//  Step 9 ALT2: calculate node value and carry
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
//  Step 10 ALT2:    current next points to new node value of sum; advance list
//********************************************************************************************************************

            current.next = new ListNode(sum);
            current = current.next;
        }

//********************************************************************************************************************
//  Step 11 ALT2:    return the reversed list
//********************************************************************************************************************

        return reverseList(dummyHead.next);
    }
};

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        // Test Case:
        // Input: l1 = [3,4,2], l2 = [4,6,5]
        // Output: [8,0,7]
        // Explanation: 342 + 465 = 807.

        Solution solution = new Solution();
        
        ListNode l1 = new ListNode(3, new ListNode(4, new ListNode(2)));
        ListNode l2 = new ListNode(4, new ListNode(6, new ListNode(5)));

        ListNode result;
        result = solution.addTwoNumbersReverse(l1, l2);

        int num = 0;
        int multiplier = 10;
        while (result != null)
        {
            num = num*multiplier + result.val;
            result = result.next;
        }
        System.out.println(num);

        ListNode l3 = new ListNode(3, new ListNode(4, new ListNode(2)));
        ListNode l4 = new ListNode(4, new ListNode(6, new ListNode(5)));

        result = solution.addTwoNumbersStack(l3, l4);

        num = 0;
        while (result != null)
        {
            num = num*multiplier + result.val;
            result = result.next;
        }
        System.out.println(num);

        ListNode l5 = new ListNode(3, new ListNode(4, new ListNode(2)));
        ListNode l6 = new ListNode(4, new ListNode(6, new ListNode(5)));

        result = solution.addTwoNumbers(l5, l6);

        num = 0;
        while (result != null)
        {
            num = num*multiplier + result.val;
            result = result.next;
        }
        System.out.println(num);
    }
};