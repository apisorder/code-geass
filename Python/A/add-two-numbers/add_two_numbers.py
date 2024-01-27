
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  7:15PM 1-23-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
                                    https://leetcode.com/problems/add-two-numbers/solutions/1340/a-summary-about-how-to-solve-linked-list-problem-c/
 NOTE:
                                    KNOW HOW LISTNODE IS DEFINED
                                    ESPECIALL DEF __INIT__:  SELF && DEFAULT VALUES
                                    HOW CARRY IS PROPOGATED W/O BEING SAVED IN NODES                          
'''

# 2. Add Two Numbers
# Medium
# 28.2K
# 5.4K
# Companies
# You are given two non-empty linked lists representing two 
# non-negative integers. The digits are stored in REVERSE order, 
# and each of their nodes contains a single digit. Add the 
# two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading 
# zero, except the number 0 itself.

# Example 1:

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.
# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]
# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]
 
# Constraints:

# The number of nodes in each linked list is in the range 
# [1, 100].
# 0 <= Node.val <= 9
# It is guaranteed that the list represents a number 
# that does not have leading zeros.
# Accepted
# 3.9M
# Submissions
# 9.4M
# Acceptance Rate
# 41.1%
    
# Definition for singly-linked list.
class ListNode:
    #   used to initialize object of a class
    #   a.k.a. the constructor
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1, l2):
        #   non-negative numbers
        #   stored in reversed order
        #   l1 -> 246
        #   6 -> 4 -> 2
        #   l2 -> 357
        #   7 -> 5 -> 3

        #   since the list is in reversed order, 
        #   there is no matching the nodes problems
        
#   create dummy head
#   create current pointer
        dummyHead = ListNode()
        current = dummyHead

#   while linked list 1 or linked list 2 or carry exists
        carry = 0
        while l1 or l2 or carry:
#   set sum to carry
            sum1 = carry

#   add linked list 1 node value to sum & advance list
            if l1:
                sum1 += l1.val
                l1 = l1.next
#   add linked list 2 node value to sum & advance list
            if l2:
                sum1 += l2.val
                l2 = l2.next

#   determine carry value
            if sum1 >= 10:
                sum1 %= 10
                carry = 1
            else:
                carry = 0

#   add node value with sum to current & advance list
            current.next = ListNode( sum1 )
            current = current.next

#   return dummy head next
        return dummyHead.next

#   REMEMBER TO CALL CONSTRUCTOR  
solution = Solution()

#   342 + 465 = 807
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))

result = solution.addTwoNumbers(l1, l2)

multiplier = 1
number = 0
while result:
    number += result.val*multiplier
    multiplier *= 10
    result = result.next
print( f"Number = {number}")