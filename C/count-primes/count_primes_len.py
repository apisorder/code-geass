
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:55PM 1-5-2024
 *  Problem:                        204. Count Primes (Medium)
 *  Reference:                      https://leetcode.com/problems/count-primes/description/
                                    https://leetcode.com/problems/count-primes/solutions/57595/fast-python-solution/
 NOTE:                              
                                    REMEMBER HOW SLICING NOTATION WORKS [K*K: N: K], NOT [K*K: K: N]                                   
                                    THINK ABOUT WHY TIME COMPLEXITY IS (N)*LOG(LOG(N))
'''

# 204. Count Primes
# Medium
# 7.6K
# 1.4K
# Companies
# Given an integer n, return the number of prime numbers that are strictly less than n.

# Example 1:

# Input: n = 10
# Output: 4
# Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
# Example 2:

# Input: n = 0
# Output: 0
# Example 3:

# Input: n = 1
# Output: 0
 

# Constraints:

# 0 <= n <= 5 * 106
# Accepted
# 806.5K
# Submissions
# 2.4M
# Acceptance Rate
# 33.4%

import math
class Solution:
    def countPrimes( self, n ):
#   using the sieve of eratosthenes
#   for every prime number encountered less than sqrt(n)
#   mark all its multiples (less than n) to be non-prime

#   since the smallest primes is 2
#   if n is less than 2, then no primes have been found
        if n < 2:
            return 0

#   otherwise
#   create a list of n numbers, all equal to 1
        numbersLeft = [1] * n
#   except list[0] and list[1] are 0's
        numbersLeft[0] = numbersLeft[1] = 0

#   mark the list using the algorithm above
        k = 2
        for k in range(2, int(n**0.5)+1):
        # while k <= math.sqrt(n):
            if numbersLeft[k] == 1:
                numbersLeft[ k*k: n: k] = [0] * len( numbersLeft[ k*k: n: k] )
#   VERY IMPORTANT TO REMEMBER TO INCREMENT K
            k += 1

#   return the result
        return sum(numbersLeft)

        