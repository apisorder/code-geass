
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  03:35PM 02-02-2024
 *  Problem:                        Set Kth Bit (Zero)
 * @param {Solution} self
 * @param {Integer} number
 * @param {Integer} kth_bit
 * @return {Integer]}
'''

class Solution:
    def set_kth_bit(self, number, kth_bit):

#********************************************************************************************************************
#  Step 1: OR the number with 1 LEFT-SHIFTED k bits will always set that bit in the number
#********************************************************************************************************************

        return (number | (1 << kth_bit))
    
solution = Solution

#   64  32  16  8   4   2   0
#   0   0   1   0   1   0   0
#   1   0   1   0   0   1   0

number1 = 20
number2 = 82
bit_to_set = 3

print( f'First number has the value of {number1} and after setting bit {bit_to_set} = {solution.set_kth_bit(solution, number1, bit_to_set)}')
print( f'Second number has the value of {number2} and after setting bit {bit_to_set} = {solution.set_kth_bit(solution, number2, bit_to_set)}')