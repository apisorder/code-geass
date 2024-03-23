
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  02:16PM 03-22-2024
 *  Problem:                        445. Add Two Numbers II (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers-ii/description/
 *  Note:                           default values __init__(self, var=0, var=None)
 *                                  NO new keyword, integer divsion == integer1 // integer2                                  
 *                                  order of invocation
 *
 *  @func       __init__
 *  @purpose    constructor for ListNode object
 *  @param      { ListNode } self
 *  @param      { Integer } val
 *  @param      { Pointer to ListNode } next
 *  @return     { None }
 *
 *  @func       reverse
 *  @purpose    reverse a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode }
 *  @return     { Pointer to ListNode }
 *
 *  @func       listLength
 *  @purpose    calculate the length of a list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode }
 *  @return     { Integer }
 *
 *  @func       addTwoNumbers                                    
 *  @purpose    add two numbers stored in linked lists & return the result in a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1
 *  @param      { Pointer to ListNode } l2
 *  @return     { Pointer to ListNode }
 *
 *  @func       addTwoNumbersII                                    
 *  @purpose    add two numbers stored in linked lists & return the result in a linked list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1
 *  @param      { Pointer to ListNode } l2
 *  @return     { Pointer to ListNode }
 *
 *  @func       printInputs
 *  @purpose    print the two input lists
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } l1ptr
 *  @param      { Pointer to ListNode } l2ptr
 *  @return     {None}
 *
 *  @func       printResult
 *  @purpose    print input lists and the result list
 *  @param      { Solution } self
 *  @param      { Pointer to ListNode } resultptr
 *  @return     {None}
'''
#
#   445. Add Two Numbers II
#
#   You are given two non-empty linked lists representing two non-negative integers. 
#   The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
#   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
#   Example 1:
#   Input: l1 = [7,2,4,3], l2 = [5,6,4]
#   Output: [7,8,0,7]
#
#   Example 2:
#   Input: l1 = [2,4,3], l2 = [5,6,4]
#   Output: [8,0,7]
#
#   Example 3:
#   Input: l1 = [0], l2 = [0]
#   Output: [0]
#
#   Constraints:
#   The number of nodes in each linked list is in the range [1, 100].
#   0 <= Node.val <= 9
#   It is guaranteed that the list represents a number that does not have leading zeros.
#
#   Follow up: Could you solve it without reversing the input lists?

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverse(self, l):
        prev = None

        while l:
            temp = l.next
            l.next = prev
            prev = l
            l = temp

        return prev
    
    def listLength(self, l):
        current = l
        
        length = 0
        while l:
            length += 1
            l = l.next

        return length

    def addTwoNumbers(self, l1, l2):
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)

        dummyHead = ListNode()
        current = dummyHead

        carry = 0
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            val = val1 + val2 + carry
            carry = val // 10
            val = val % 10

            current.next = ListNode(val)
            current = current.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return self.reverse(dummyHead.next)

    def addTwoNumbersII(self, l1, l2):
        dummyHead = ListNode()
        
        l1_length = self.listLength(l1)
        l2_length = self.listLength(l2)

        while (l1_length > 0) and (l2_length > 0):
            val = 0
            if l1_length >= l2_length:
                val += l1.val
                l1 = l1.next
                l1_length -= 1

            if l1_length < l2_length:
                val += l2.val 
                l2 = l2.next
                l2_length -= 1

            head = ListNode(val, dummyHead)
            dummyHead = head

        current = dummyHead
        dummyHead = None

        carry = 0
        while current:
            val = carry + current.val

            carry = val // 10
            val = val % 10
            # 123 + 456
            # 6 -> 5 -> 4
            # 3 -> 3 -> 1
            head = ListNode(val, dummyHead)
            dummyHead = head
            current = current.next

        if dummyHead.val == 0:
            return dummyHead.next
        else:
            return dummyHead
        
    def printInputs(self, l1ptr, l2ptr):
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

    def printResult(self, resultptr):

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

solution.printInputs(l1, l2)
solution.printResult(solution.addTwoNumbers(l1, l2))
solution.printInputs(l3, l4)
solution.printResult(solution.addTwoNumbers(l3, l4))
solution.printInputs(l5, l6)
solution.printResult(solution.addTwoNumbers(l5, l6))

#   Example 1:
#   Input: l1 = [2,4,3], l2 = [5,6,4]
#   Output: [7,0,8]
#   Explanation: 342 + 465 = 807.    
l7 = ListNode(2, ListNode(4, ListNode(3)))
l8 = ListNode(5, ListNode(6, ListNode(4)))

#   Example 2:
#   Input: l1 = [0], l2 = [0]
#   Output: [0]
#   Explanation:  0 + 0 = 0.
l9 = ListNode(0)
l10 = ListNode(0)

#   Example 3:
#   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
#   Output: [8,9,9,9,0,0,0,1]
#   Explanation:  99999999 + 9999 = 10009998
l11 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
l12 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))

solution.printInputs(l7, l8)
solution.printResult(solution.addTwoNumbersII(l7, l8))
solution.printInputs(l9, l10)
solution.printResult(solution.addTwoNumbersII(l9, l10))
solution.printInputs(l11, l12)
solution.printResult(solution.addTwoNumbersII(l11, l12))
