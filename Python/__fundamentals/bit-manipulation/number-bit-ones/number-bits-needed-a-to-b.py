
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  05:31PM 02-11-2024
 *  Problem:                        Number Of Bits Which Are One (Zero)
 * @param {Solution} self
 * @param {Integer} number1
 * @return {Integer}
'''

class Solution:
    def number_of_bit_ones(self, number):

        sum1 = 0

        while number > 0:

#********************************************************************************************************************
#  Step 1: while number is not 0, count the number of 1's
#********************************************************************************************************************

            number = number & (number-1)
            sum1 += 1

        return sum1
    
solution = Solution

#   64  32  16  8   4   2   0
#   0   0   1   0   1   0   0
#   1   0   1   0   0   1   0

number1 = 20
number2 = 82

print( f'{number1} has {solution.number_of_bit_ones(solution, number1)} bit(s), which are one')
print( f'{number2} has {solution.number_of_bit_ones(solution, number2)} bit(s), which are one')
