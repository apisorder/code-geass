
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:31PM 1-22-2024
 *  Problem:                        Swap Two Numbers (Zero)
 *  Reference:                      https://stackoverflow.com/questions/249423/how-does-xor-variable-swapping-work
 NOTE:
                                    swap(a, b){ return b, a }
'''

class Solution:
    def swap_two_numbers(self, a, b):
        #   return the swapped elements
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
