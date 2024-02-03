
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  01:19PM 02-02-2024
 *  Problem:                        Determine Number Is Even Or Odd (Zero)
 * @param {Solution} self
 * @param {Integer} number
 * @return {String}
'''

class Solution:
    def number_even_or_odd_slow(self, number):

#********************************************************************************************************************
#  Step 1:  if a number is even, number % 2 should have a reminder of 0  
#********************************************************************************************************************

        if number % 2 == 0:
            return "even"
        else:
            return "odd"
    
    def number_even_or_odd_fast(self, number):

#********************************************************************************************************************
#  Step 1 ALT: since a even number will never have bit 0 set, AND the number with 1 will always be 0
#********************************************************************************************************************

        if number & 1 == 0:
            return "even"
        else:
            return "odd"

solution = Solution

number1 = 3
number2 = 14

print( f'First number has the value of {number1} and is {solution.number_even_or_odd_slow(solution, number1)}')
print( f'Second number has the value of {number2} and is {solution.number_even_or_odd_fast(solution, number2)}')

#   2 -> 10
#   4 -> 100
#   6 -> 110
#   all evens have the last bit zero

#   3 -> 11
#   7 -> 111
#   9 -> 1001
#   all odds have the last bit one

#   111
#  &001
#     1

#   110
#  &001
#     0