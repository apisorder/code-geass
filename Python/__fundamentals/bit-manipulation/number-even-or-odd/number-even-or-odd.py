
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:29PM 1-22-2024
 *  Problem:                        Determine Number Is Even Or Odd (Zero)
'''

class Solution:
    def number_even_or_odd_slow(self, number):
        if number % 2 == 0:
            return "even"
        else:
            return "odd"
    
    def number_even_or_odd_fast(self, number):
        if number & 1 == 0:
            return "even"
        else:
            return "odd"

solution = Solution

number1 = 3
number2 = 14

print( f'First number has the value of {number1} and is {solution.number_even_or_odd_slow(solution, number1)}')
print( f'Second number has the value of {number2} and is {solution.number_even_or_odd_fast(solution, number2)}')

#   2 -> 10
#   4 -> 100
#   6 -> 110
#   all evens have the last bit zero

#   3 -> 11
#   7 -> 111
#   9 -> 1001
#   all odds have the last bit one

#   111
#  &001
#     1

#   110
#  &001
#     0