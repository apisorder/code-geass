
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:19PM 1-31-2024
 *  Problem:                        Number Of Bits Needed A To B (Zero)
'''

class Solution:
    def number_of_bits_needed_a_to_b(self, number1, number2):
        result = number1 ^ number2
        numberOfBits = 0

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