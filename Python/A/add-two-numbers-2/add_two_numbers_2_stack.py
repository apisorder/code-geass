
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:32PM 1-3-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 NOTE:                              
                                    MOST IMPORTANT 1    HOW TO CALCULATE CARRY
                                    MOST IMPORTANT 2    HOW TO INCLUDE CARRY IN CALCULATION

                                    inside while loop, init sum to current.val (carry from before)
                                        i.e. sum = dummyhead.val

                                    and therefore must...
                                    
                                    dummyHead.val = sum
                                    head = ListNode( carry, dummyHead )
 NOTE:                                  HEAD = LISTNODE( CARRY, LISTNODE(SUM)) IS WRONG
                                    dummyHead = head
 *@param {ListNode} l1
 *@param {ListNode} l2
 *@return {ListNode}
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

from collections import deque

#********************************************************************************************************************
#  Step 1: define node
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

#   two linked lists with normal order,
#   therefore, lists need to be reversed so calculations don't ripple
#   
#   NOTE:   ADDING LINKED LINKS IN NORMAL ORDER INVOLVES MATCHING NODES
#   OF SAME SIGNFICANCE
#
#   a harder way to do this without actually reversing the lists to use a stack
#
#   create a function to convert list to stack
        
#********************************************************************************************************************
#  Step 2: define helper function to push list onto the stack, effectively reversing the list
#********************************************************************************************************************

        def listToStack(self, l):
#   create a stack using deque
            stack = deque()
#   while list exists
#   push list value onto the stack & advance the list
            while l:

#********************************************************************************************************************
#  Step 3: push list node onto the stack; advance the list
#********************************************************************************************************************

                stack.append( l.val )
                l = l.next
#   return the stack
                
#********************************************************************************************************************
#  Step 4: return result
#********************************************************************************************************************

            return stack
        
#
#   convert linked list 1 to stack
#   convert linked list 2 to stack
        
#********************************************************************************************************************
#  Step 5: push the lists onto the stack for easier processing
#********************************************************************************************************************

        stack1 = listToStack( self, l1 )
        stack2 = listToStack( self, l2 )

#********************************************************************************************************************
#  Step 6: create dummy head for the new list
#********************************************************************************************************************

#   create dummy head
        dummyHead = ListNode()

#   while stack 1 or stack 2 exists
        
#  stack 1      ->  node x-1                  ->  node x-2                          ->  node x-3                          -> ...
#  stack 2      ->  node x-1                  ->  node x-2                          ->  node x-3
#  sum = dummy head value
#  head -> carry; dummy head val = (node x-1 x 2)
#  dummy head -> head   
#********************************************************************************************************************
#  Step 7: while either stack remains
#********************************************************************************************************************

        while stack1 or stack2:
#
#   NOTE:   IF SET SUM TO CARRY, RESULT WOULD BE WRONG
#   This is because the list will always end with a node with 0 value
#   because the code would be head = ListNode( sum, dummyHead )
#   instead of head = ListNode( carry, dummyHead )
#
#   set sum to dummy head value
            
#********************************************************************************************************************
#  Step 8: dummy head value is first added to the sum
#********************************************************************************************************************

            sum1 = dummyHead.val

#   pop stack 1 and add value to sum
#   pop stack 2 and add value to sum
            
#********************************************************************************************************************
#  Step 9: pop node from stack 1 and add value to the sum, if stack not empty
#********************************************************************************************************************

            if stack1:
                sum1 += stack1.pop()

#********************************************************************************************************************
#  Step 10:    pop node from stack 2 and add value to the sum, if stacj not empty
#********************************************************************************************************************

            if stack2:
                sum1 += stack2.pop()

#   calculate carry
                
#********************************************************************************************************************
#  Step 11:    calculate node value and carry
#********************************************************************************************************************

            if sum1 >= 10:
                sum1 %= 10
                carry = 1
            else:
                carry = 0

#   set dummy head to sum   
#   point head to carry and next to dummy head
#   point dummy head to head (create the result list in reverse)  
                
#********************************************************************************************************************
#  Step 12:    assign sum to dummy head value
#********************************************************************************************************************

            dummyHead.val = sum1

#********************************************************************************************************************
#  Step 13:    add the new node to the new list; advance the list
#********************************************************************************************************************

            head = ListNode( carry, dummyHead )
            dummyHead = head
            
#   depending on the value of dummy head
#   return the result list
            
#********************************************************************************************************************
#  Step 14:    depending on dummy head value, return the appropriate node value
#********************************************************************************************************************

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