
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:13PM 1-31-2024
 *  Problem:                        Clear Kth Bit (Zero)
'''

class Solution:
    def clear_kth_bit(self, number, kth_bit):
        #   remember to negate it
        return (number & (~(1 << kth_bit)))
    
solution = Solution

#   64  32  16  8   4   2   0
#   0   0   1   0   1   0   0
#   1   0   1   0   0   1   0

number1 = 20
number2 = 82
bit_to_clear = 4

print( f'First number has the value of {number1} and after clearing bit {bit_to_clear} = {solution.clear_kth_bit(solution, number1, bit_to_clear)}')
print( f'Second number has the value of {number2} and after clearing bit {bit_to_clear} = {solution.clear_kth_bit(solution, number2, bit_to_clear)}')