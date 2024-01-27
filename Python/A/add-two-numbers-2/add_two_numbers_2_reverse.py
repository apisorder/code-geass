
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  5:36PM 1-3-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
'''

# 445. Add Two Numbers II
# Medium
# 5.7K
# 278
# Companies
# You are given two non-empty linked lists representing 
# two non-negative integers. The most significant digit 
# comes first and each of their nodes contains a single 
# digit. Add the two numbers and return the sum as 
# a linked list.

# You may assume the two numbers do not contain any 
# leading zero, except the number 0 itself.

 

# Example 1:


# Input: l1 = [7,2,4,3], l2 = [5,6,4]
# Output: [7,8,0,7]
# Example 2:

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [8,0,7]
# Example 3:

# Input: l1 = [0], l2 = [0]
# Output: [0]
 

# Constraints:

# The number of nodes in each linked list is 
# in the range [1, 100].
# 0 <= Node.val <= 9
# It is guaranteed that the list represents a number 
# that does not have leading zeros.
 

# Follow up: Could you solve it without reversing 
# the input lists?

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# We are told that the most significant digit comes first, 
# and that each of their nodes includes a single digit. 
# To do a basic addition of two numbers using a sum of two digits and a carry, 
#  we must start with the least significant digits (the lowest place) 
# and work our way up to the most significant digits.

# To get the order of digits from the least significant digits 
# to the the most significant digits, we can reverse the given lists 
# so the least significant digits come first.

# We can then iterate over the reversed lists to perform the addition 
# of digits at corresponding places similar to the first approach.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1, l2):
        #   normal order
        #   l1 -> 586
        #   5 -> 8 -> 6
        #   l2 -> 143
        #   1 -> 4 -> 3

        #   two linked list in normal order;
        #   therefore, reversing the list helps with carry calculation
        #   and is the easiest approach

#   NOTE:   ADDING LINKED LINKS IN NORMAL ORDER INVOLVES MATCHING NODES
#   OF SAME SIGNFICANCE

#   create a function to reverse the linked list
#   previous -> current -> next
#   previous <- current <- next    
        def reverseList( self, l ):
#   set previous to nothing
            previous = None

#   while current exists
            while l:

#   save the original next
#   set next to previous
#   set previous to current
#   set current to saved next
                nexter = l.next
                l.next = previous
                previous = l
                l = nexter

#   return previous
            return previous
        
#   
#   reverse linked list 1
#   reverse linked list 2
        #   NESTED FUNCTION SO PASS SELF IN
        l1 = reverseList( self, l1 )
        l2 = reverseList( self, l2 )

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

#   calculate carry
            if sum1 >= 10:
                sum1 %= 10
                carry = 1
            else:
                carry = 0

#   add node with sum value to current
            current.next = ListNode( sum1 )
#   advance current
            current = current.next

#   reverse dummy head next
#   return the result    
        return reverseList( self, dummyHead.next )
    
solution = Solution()

#   243 + 564 = 807
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))

result = solution.addTwoNumbers(l1, l2)

# result = 8->0->7
number = 0
while result:
    number = number*10 + result.val
    result = result.next
print(f'Number = {number}')