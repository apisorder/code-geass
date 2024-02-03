
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  04:23PM 02-02-2024
 *  Problem:                        Swap Two Numbers (Zero)
 *  Reference:                      https://stackoverflow.com/questions/249423/how-does-xor-variable-swapping-work
 NOTE:
                                    swap(a, b){ return b, a }
 * @param {Solution} self
 * @param {Integer} a
 * @param {Integer} b
 * @return {Tuple}
'''

class Solution:
    def swap_two_numbers(self, a, b):
        #   return the swapped elements

#********************************************************************************************************************
#  Step 1: return the two numbers in the reverse order
#********************************************************************************************************************

        return b, a

solution = Solution
a = 7
b = 11
print('values before the function call')
print(f'a = {a}')
print(f'b = {b}')

#   now assign them
a, b = solution.swap_two_numbers(solution, a, b)

print('values after the function call')
print(f'a = {a}')
print(f'b = {b}')
