
class Solution:
    def number_even_or_odd_slow(self, number):
        if number % 2 == 0:
            return "Even"
        else:
            return "Odd"
    
    def number_even_or_odd_fast(self, number):
        if number & 1 == 0:
            return "Even"
        else:
            return "Odd"

solution = Solution
print(solution.number_even_or_odd_slow(solution, 3));
print(solution.number_even_or_odd_slow(solution, 14));

print(solution.number_even_or_odd_fast(solution, 3));
print(solution.number_even_or_odd_fast(solution, 14));

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