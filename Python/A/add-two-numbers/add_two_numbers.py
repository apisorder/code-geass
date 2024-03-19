
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  06:40PM 03-18-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https:#leetcode.com/problems/add-two-numbers/description/
                                    https:#leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/                                                                        
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
'''
#
#   2. Add Two Numbers
#
#   You are given two non-empty linked lists representing two non-negative integers. 
#   The digits are stored in reverse order, and each of their nodes contains a single digit. 
#   Add the two numbers and return the sum as a linked list.
#
#   You may assume the two numbers do not contain any leading zero, 
#   except the number 0 itself.
#
#   Example 1:
#   Input: l1 = [2,4,3], l2 = [5,6,4]
#   Output: [7,0,8]
#   Explanation: 342 + 465 = 807.
#
#   Example 2:
#   Input: l1 = [0], l2 = [0]
#   Output: [0]
#
#   Example 3:
#   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
#   Output: [8,9,9,9,0,0,0,1]
#
#   Constraints:
#
#   The number of nodes in each linked list is in the range [1, 100].
#   0 <= Node.val <= 9
#   It is guaranteed that the list represents a number that does not have leading zeros.
#
#   non-empty
#   non-negative integers
#   reverse order
#
#   NOTE:
#   https:#www.youtube.com/watch?v=wgFPrzTjm7s
#
#   Input:  ( 2 -> 4 -> 3 ) + ( 5 -> 6 -> 4 )
#   Output: 7 -> 0 -> 8
#   Explanation:    342 + 465 = 807
#
#         1 (carry)
#         342
#     +   465
#   -------------------
#         807
#   a lot of edge cases
#
#   Edge Cases:
#
#   what if the two linked lists we are adding are of different sizes
#   3342 + 465
#
#   start at the 1's the place
#   then the 10's place
#   etc.
#
#   edge case where the numbers are of different length
#
#   (5)->(6)->(4)->(X) if X assumed 0
#   (2)->(4)->(3)->(3)
#       1
#   (7)->(0)->(8)->(3)
#
#   another edge case where the carry may be forgotten
#
#   7 + 8
#
#   carry = 1   7
#   +           8
#   _____________
#             5
#   you may forget put the 1 (carry) in the result

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        dummyHead = ListNode()
        current = dummyHead

        carry = 0
        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            val = v1 + v2 + carry
            carry = val // 10
            val = val % 10

            current.next = ListNode(val)
            current = current.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummyHead.next

    def printResults(self, l1ptr, l2ptr, resultptr):
        result = "List 1 of [ "
        while l1ptr != None:
            result += " (" + str(l1ptr.val) + ") "
            l1ptr = l1ptr.next
        result += " ] + List 2 of [ "

        while (l2ptr != None):
            result += " (" + str(l2ptr.val) + ") "
            l2ptr = l2ptr.next
        result += " ] = "

        print(result)

        result = "Result List of [ "
        while resultptr != None:
            result += " (" + str(resultptr.val) + ") "
            resultptr = resultptr.next
        result += " ]"

        print(result)
        print()

solution = Solution()

#   Example 1:
#   Input: l1 = [2,4,3], l2 = [5,6,4]
#   Output: [7,0,8]
#   Explanation: 342 + 465 = 807.    
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))

#   Example 2:
#   Input: l1 = [0], l2 = [0]
#   Output: [0]
#   Explanation:  0 + 0 = 0.
l3 = ListNode(0)
l4 = ListNode(0)

#   Example 3:
#   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
#   Output: [8,9,9,9,0,0,0,1]
#   Explanation:  99999999 + 9999 = 10009998
l5 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
l6 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))

solution.printResults(l1, l2, solution.addTwoNumbers(l1, l2))
solution.printResults(l3, l4, solution.addTwoNumbers(l3, l4))
solution.printResults(l5, l6, solution.addTwoNumbers(l5, l6))