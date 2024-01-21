class Solution:
    def swap_two_numbers(self):
        global a
        global b
        print('inside function call before swap')
        print(f'a = {a}')
        print(f'b = {b}')
        temp = a
        a = b
        b = temp

        print('inside function call after swap')
        print(f'a = {a}')
        print(f'b = {b}')

solution = Solution
a = 7
b = 11
print('values before the function call')
print(f'a = {a}')
print(f'b = {b}')
solution.swap_two_numbers(solution)
print('values after the function call')
print(f'a = {a}')
print(f'b = {b}')