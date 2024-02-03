
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:08AM 02-02-2024
 *  Problem:                        Number Of Bits Needed A To B (Zero)
 * @param {Solution} self
 * @param {Integer} number1
 * @param {Integer} number1
 * @return {Integer}
'''

class Solution:
    def number_of_bits_needed_a_to_b(self, number1, number2):

#********************************************************************************************************************
#  Step 1: XOR the two numbers to get a number of their differences 
#********************************************************************************************************************

        result = number1 ^ number2
        numberOfBits = 0

#********************************************************************************************************************
#  Step 2: calculate the number of bits where the two numbers are different
#********************************************************************************************************************

        while result > 0:
            numberOfBits += (result & 1)
            result >>= 1

        return numberOfBits
    
solution = Solution

#   64  32  16  8   4   2   0
#   0   0   1   0   1   0   0
#   1   0   1   0   0   1   0

number1 = 20
number2 = 82

print( f'First number has the value of {number1}')
print( f'Second number has the value of {number2}')
print(f'The number of bits needed to convert the numbers = {solution.number_of_bits_needed_a_to_b(solution, number1, number2)}')