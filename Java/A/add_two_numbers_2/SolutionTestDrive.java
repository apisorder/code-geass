
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  6:19PM 1-26-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
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
    int listLength(ListNode l)
    {
        int length = 0;

        while (l != null)
        {
            length += 1;
            l = l.next;
        }
        return length;
    }

    Stack<Integer> listToStack(ListNode l)
    {
        Stack<Integer> stack = new Stack<Integer>();

        while (l != null)
        {
            stack.push(l.val);
            l = l.next;
        }
        return stack;
    }

    ListNode reverseList(ListNode l)
    {
        ListNode prev = null;
        ListNode nexter;

        while (l != null)
        {
            nexter = l.next;
            l.next = prev;
            prev = l;
            l = nexter;
        }
        return prev;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        int l1_length = listLength(l1);
        int l2_length = listLength(l2);

        
        ListNode dummyHead = new ListNode(0);
        int sum = 0;

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

            ListNode head = new ListNode(sum, dummyHead);
            dummyHead = head;
        }

        ListNode current = dummyHead;
        dummyHead = null;

        int carry = 0;
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

            ListNode head = new ListNode(sum, dummyHead);
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

    public ListNode addTwoNumbersStack(ListNode l1, ListNode l2)
    {
        Stack<Integer> stack1 = listToStack(l1);
        Stack<Integer> stack2 = listToStack(l2);

        ListNode dummyHead = new ListNode(0);

        int sum = 0;
        int carry = 0 ;

        while (!stack1.empty() || !stack2.empty())
        {
            sum = dummyHead.val;

            if (!stack1.empty())
            {
                sum += stack1.pop();
            }
            if (!stack2.empty())
            {
                sum += stack2.pop();
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

            dummyHead.val = sum;
            ListNode head = new ListNode(carry, dummyHead);
            dummyHead = head;
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

    public ListNode addTwoNumbersReverse(ListNode l1, ListNode l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode dummyHead = new ListNode();
        ListNode current = dummyHead;

        int carry = 0;
        int sum = 0;

        while ((l1 != null) || (l2 != null) || (carry == 1))
        {
            sum = carry;

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