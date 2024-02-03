
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  04:31PM 02-02-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 * @param {Solution} self
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
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

#********************************************************************************************************************
#  Step 1: add the new node to the new list; advance the list
#********************************************************************************************************************

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

#********************************************************************************************************************
#  Step 2: define helper function to reverse the list for easier processing
#********************************************************************************************************************

        # @param {ListNode} l
        # @return {ListNode}    
        def reverseList( self, l ):
#   set previous to nothing
            
#********************************************************************************************************************
#  Step 3: initialize previous to point to what the end of the list is pointing
#********************************************************************************************************************

            previous = None

#   while current exists
            while l:

#   save the original next
#   set next to previous
#   set previous to current
#   set current to saved next
                
#********************************************************************************************************************
#  Step 4: save current node's next
#********************************************************************************************************************

                nexter = l.next

#********************************************************************************************************************
#  Step 5: set current node's next to point to what comes before it, i.e. reversing the list direction 
#********************************************************************************************************************

                l.next = previous
 
#********************************************************************************************************************
#  Step 6: update previous and current for the next iteration
#********************************************************************************************************************

                previous = l
                l = nexter

#   return previous
                
#********************************************************************************************************************
#  Step 7: return result
#********************************************************************************************************************

            return previous
        
#   
#   reverse linked list 1
#   reverse linked list 2
        #   NESTED FUNCTION SO PASS SELF IN

#********************************************************************************************************************
#  Step 8: reverse the input list for easier processing
#********************************************************************************************************************

        l1 = reverseList( self, l1 )
        l2 = reverseList( self, l2 )

#   create dummy head
#   create current pointer
        
#********************************************************************************************************************
#  Step 9: create dummy head and current for the new list
#********************************************************************************************************************

        dummyHead = ListNode()
        current = dummyHead

#   while linked list 1 or linked list 2 or carry exists
        carry = 0
        sum1 = 0

#  l1      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
#  l2      ->  node x-3                  ->  node x-2                          ->  node x-1                          -> ...
#  current ->  (carry(0) + node x-3 x 2) ->  (carry(node x-3 x 2) + node x-2 x 2) ->  (carry(node x-2 x 2) + node x-1 x 2) -> ...
#  sum = carry
#********************************************************************************************************************
#  Step 10:    while either list remains or carry is 1
#********************************************************************************************************************

        while l1 or l2 or carry:

#   set sum to carry
            
#********************************************************************************************************************
#  Step 11:    carry is first added to the sum
#********************************************************************************************************************

            sum1 = carry

#   add linked list 1 node value to sum & advance list
            
#********************************************************************************************************************
#  Step 12:    add node value to the sum, if list 1 exists; advance the list
#********************************************************************************************************************

            if l1:
                sum1 += l1.val
                l1 = l1.next
#   add linked list 2 node value to sum & advance list
                
#********************************************************************************************************************
#  Step 13:    add node value to the sum, if list 2 exists; advance the list
#********************************************************************************************************************

            if l2:
                sum1 += l2.val
                l2 = l2.next

#   calculate carry
                
#********************************************************************************************************************
#  Step 14:    calculate node value and carry
#********************************************************************************************************************

            if sum1 >= 10:
                sum1 %= 10
                carry = 1
            else:
                carry = 0

#********************************************************************************************************************
#  Step 15:    add the new node to the new list; advance the list
#********************************************************************************************************************

#   add node with sum value to current
            current.next = ListNode( sum1 )
#   advance current
            current = current.next

#   reverse dummy head next
#   return the result    
            
#********************************************************************************************************************
#  Step 16:    return the reversed list
#********************************************************************************************************************

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