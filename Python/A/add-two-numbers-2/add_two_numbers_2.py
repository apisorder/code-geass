
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:33PM 1-3-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 NOTE:                              
                                    MOST IMPORTANT 1    HOW TO CALCULATE CARRY
                                    MOST IMPORTANT 2    HOW TO INCLUDE CARRY IN CALCULATION
                                    
                                    during first pass, sum = 0
                                    head = ListNode( sum, dummyHead )
                                    dummyHead = head

                                    during second pass, sum = 0 also
                                    then sum = current.val + carry

                                    head = ListNode( sum, dummyHead )
                                    dummyHead = head
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

#   NOTE:   ADDING NODES IN THE NORMAL ORDER REQUIRE MATCHING UP NODES
#   OF SAME SIGNFICANCE
#   
#   one way to do this would be to reverse the list (easiest), or to
#   use a stack, but if neither is possible, then we can simply create
#   the resulting list twice, to allow proper processing of nodes
#
#   The goal is easy -> during first pass, grow the list in reverse
#   this allows us to effectively reverse the list
#   -> during the second pass, again grow the list in reverse
#   this allows nodes to be properly handled and the result list
#   to be in normal order
#
#   to ensure the list is created properly
#   create a function that determines the list length
        def listLength( self, l ):
#
#   set length to 0
            length = 0
#   while list exists
#   increment length & advance the list
            while l:
                length += 1
                l = l.next
#   return length
            return length

#   calculate length of list 1
#   calculate lenght of list 2
        l1_length = listLength( self, l1 )
        l2_length = listLength( self, l2 )

#   create dummy head
        dummyHead = ListNode()

#
#   during first pass
#
#   while length of list 1 and length of list 2 are both > 0
#   set sum to 0
        while l1_length and l2_length:
            sum1 = 0
#   if length of list 1 >= list 2
#   add its value to sum & advance list & decrement lenght of list 1
            if l1_length >= l2_length:
                sum1 += l1.val
                l1 = l1.next
                l1_length -= 1
#   if length of list 1 < list 2
#   add its value to sum & advance list & decrement lenght of list 2
            if l1_length < l2_length:
                sum1 += l2.val
                l2 = l2.next
                l2_length -= 1

#   set head value to sum and next to dummy head
#   point dummy head to head
            head = ListNode( sum1, dummyHead )
            dummyHead = head

#   now second pass
#   
#   create current pointer
#   set dumm head to nothing (the result list to be returned)
        current = dummyHead
        dummyHead = None
        
#   sum = 0
#   while current exists
        carry = 0
        while current:

#   NOTE:   SET SUM TO CARRY AND CURRENT.VAL
#
#   NOTE:   DUMMY HEAD POINTS TO NOTHING IN THE BEGINNING
#   SO DUMMYHEAD.VAL WOULD NOT WORK
            sum1 = carry + current.val 

#   calculate carry
            if sum1 >= 10:
                sum1 %= 10
                carry = 1
            else:
                carry = 0

#   set head to point to sum with next to dummy head
#   set dummy head to head
            head = ListNode( sum1, dummyHead )
            dummyHead = head
#   advance list
            current = current.next

#   depending on value of dummy head, return the list
        if dummyHead.val == 0:
            return dummyHead.next
        else:
            return dummyHead
        
solution = Solution()

#   243 + 564 = 807
l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))

result = solution.addTwoNumbers(l1, l2)

number = 0
while result:
    number = number*10 + result.val
    result = result.next

print(f"Number = {number}")
