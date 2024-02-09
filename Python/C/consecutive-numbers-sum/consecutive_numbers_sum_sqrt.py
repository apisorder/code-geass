
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:28PM 02-05-2024
 *  Problem:                        829. Consecutive Numbers Sum (Hard)
 *  Reference:                      https://leetcode.com/problems/consecutive-numbers-sum/description/
                                    https://leetcode.com/problems/consecutive-numbers-sum/solutions/129015/5-lines-c-solution-with-detailed-mathematical-explanation/
 NOTE:                              
                                    REMEMBER WHAT K MEANS
                                    REMEMBER WHAT RESULT SHOULD INIT TO 
                                    REMEMBER TO CAST MATH.SQRT(2*N)
 *@param {Solution} self
 *@param {Integer} n
 *@return {Integer}
'''

# 829. Consecutive Numbers Sum
# Hard
# 1.3K
# 1.4K
# Companies
# Given an integer n, return the number of ways you can 
# write n as the sum of consecutive positive integers.

 
# Example 1:

# Input: n = 5
# Output: 2
# Explanation: 5 = 2 + 3
# Example 2:

# Input: n = 9
# Output: 3
# Explanation: 9 = 4 + 5 = 2 + 3 + 4
# Example 3:

# Input: n = 15
# Output: 4
# Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 

# Constraints:

# 1 <= n <= 109
# Accepted
# 81.7K
# Submissions
# 196.1K
# Acceptance Rate
# 41.7%

    #   a number can be written as a sequence of consecutive numbers
    #   n = x + (x+1) + (x+2) + (x+3) + ... + (x+k-1) -> k numbers
    #   n = kx + (1+2+3+...+k-1) = kx + k(k-1)/2
    #   kx = n - k(k-1)/2 -> both sides multiples of k i.e. kx % k == 0 and (n - k(k-1)/2) %k == 0
    #   since k > 0 and x > 0, n - k(k-1)/2 > 0
    #   n - k(k-1)/2 > 0
    #   2n > k(k-1)
    #   so approximately 2n > k**2
    #   or k < sqrt(2n)
    #   since it's a sequence, k >= 2
    #   however, since the question expects the number itself
    #   as a sequence, we will start the count at 1
        # numberOfSequences = 1
        # k = 2
        # while k < math.sqrt(2*n):
        #     if (n - k*(k-1)//2) % k == 0:
        #         numberOfSequences += 1
        #     k += 1

        # return numberOfSequences

# import math
# class Solution:
#     def consecutiveNumbersSum( self, n ):

#         numOfWays = 1
#         for k in range(2, int(math.sqrt(2*n))+1):
#             if (n - k*(k-1)//2) % k == 0:
#                 numOfWays += 1

#         return numOfWays


import math
class Solution:
    def consecutiveNumbersSum(self, n):

#********************************************************************************************************************
#  Step 1: the number itself is a sequence of k, where k = 1
#********************************************************************************************************************

        numOfWays = 1

#********************************************************************************************************************
#  Step 2: from k between 2 and square root of 2xn
#********************************************************************************************************************

        for k in range(2, int(math.sqrt(2*n))+1):

#********************************************************************************************************************
#  Step 3: if the equation is a multiple of k
#********************************************************************************************************************

            if (n - k*(k-1)//2) % k == 0:

#********************************************************************************************************************
#  Step 4: one more solution has been found
#********************************************************************************************************************

                numOfWays += 1

#********************************************************************************************************************
#  Step 5: return the result
#********************************************************************************************************************

        return numOfWays
    
solution = Solution()
# Example 1:

# Input: n = 5
# Output: 2

# Example 2:
# Input: n = 9
# Output: 3

#  Example 3:
# Input: n = 15
# Output: 4
number1 = 5
number2 = 9 
number3 = 15

print(solution.consecutiveNumbersSum(number1))
print(solution.consecutiveNumbersSum(number2))
print(solution.consecutiveNumbersSum(number3))


#   a number can be written as the sum of consecutive number
#   this sequence is unique, because the sum will be smaller
#   if the starting number is smaller
#   and will be larger if the ending number is larger
#
#   expressed mathematically
#   n = x + x+1 + x+2 + ... + x+k-1
#   collect like terms
#   n = kx + k(k-1)/2
#   kx = n - k(k-1)/2       (EQU 1)
#   obviously kx is a multiple of k
#   since LHS == RHS, if n - k(k-1)/2 is also a multiple of k
#   a solution is found, i.e. (n - k(k-1)/2) % k == 0 (EQU 2)
#   now to determine the range of k
#   from EQU 1, k must be greater than 0, or 1, since we are dealing with integers
#   from EQU 2, we can conclude that n - k(k-1)/2 > 0
#   2n > k(k-1)
#   by approximation, 2n > k**2
#   or k < sqrt(2n)
        
#   set number of solutions to 1

#   start at two, because we can always write n as a sequence of 1, which is itself
#
#   PS: OJ expects the answer to be 1 greater than the number of possible ways 
#   because it considers N as being written as N itself. It's confusing 
#   since they ask for sum of consecutive integers which implies at least 2 numbers. 
#   But to please OJ, we should start count from 1.

#   ESSENTIALLY, we can construct a sum of N using k terms starting from x

#   while k < sqrt(2n)

#   if EQU2 is true
#   number of solution increments
#   increments k
#   return number of solutions
