
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:31PM 1-22-2024
 *  Problem:                        Swap Two Numbers (Zero)
 NOTE:
                                    swap(a, b){ return b, a }
'''

class Solution:
    def swap_two_numbers(self, a, b):
        return b, a

solution = Solution
a = 7
b = 11
print('values before the function call')
print(f'a = {a}')
print(f'b = {b}')

a, b = solution.swap_two_numbers(solution, a, b)

print('values after the function call')
print(f'a = {a}')
print(f'b = {b}')
