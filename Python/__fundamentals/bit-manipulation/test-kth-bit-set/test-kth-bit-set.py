
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:44AM 02-03-2024
 *  Problem:                        Test If Kth Bit Is Set (Zero)
 * @param {Solution} self
 * @param {Integer} number
 * @param {Integer} kth_bit
 * @return {Integer}
'''

class Solution:
    def test_kth_bit_set(self, number, kth_bit):

#********************************************************************************************************************
#  Step 1: LEFT-SHIFT 1 k bits and AND it with the number will test whether kth bit is set (1) or not (0)
#********************************************************************************************************************

        return (number & (1 << kth_bit))
    
solution = Solution

#  64  32  16  8   4   2   0
#  1   0   0   1   0   0   0
#  0   0   1   0   1   0   0

number1 = 72;
number2 = 20;
kthBit1 = 3;
kthBit2 = 6;

print( f'First number has the value of {number1}')
print( f'Its bit {kthBit1} has the value of {"1" if solution.test_kth_bit_set(solution, number1, kthBit1) else "0"}')
print( f'Second number has the value of {number2}')
print( f'Its bit {kthBit2} has the value of {"1" if solution.test_kth_bit_set(solution, number2, kthBit2) else "0"}')