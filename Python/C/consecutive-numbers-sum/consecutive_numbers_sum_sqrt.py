
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  8:22PM 1-4-2024
 *  Problem:                        829. Consecutive Numbers Sum (Hard)
 *  Reference:                      https://leetcode.com/problems/consecutive-numbers-sum/description/
                                    https://leetcode.com/problems/consecutive-numbers-sum/solutions/129015/5-lines-c-solution-with-detailed-mathematical-explanation/
 NOTE:                              
                                    REMEMBER WHAT K MEANS
                                    REMEMBER WHAT RESULT SHOULD INIT TO 
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

import math
class Solution:
    def consecutiveNumbersSum( self, n ):
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
        numberOfSolutions = 1

#   start at two, because we can always write n as a sequence of 1, which is itself
#
#   PS: OJ expects the answer to be 1 greater than the number of possible ways 
#   because it considers N as being written as N itself. It's confusing 
#   since they ask for sum of consecutive integers which implies at least 2 numbers. 
#   But to please OJ, we should start count from 1.
        k = 2

#   ESSENTIALLY, we can construct a sum of N using k terms starting from x

#   while k < sqrt(2n)
        while k < math.sqrt( 2*n ):
#   if EQU2 is true
#   number of solution increments
            if (n - k*(k-1)//2) % k == 0:
                numberOfSolutions += 1
#   increments k
            k += 1
#   return number of solutions
        return numberOfSolutions
