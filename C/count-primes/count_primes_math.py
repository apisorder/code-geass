
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:43PM 1-14-2024
 *  Problem:                        204. Count Primes (Medium)
 *  Reference:                      https://leetcode.com/problems/count-primes/description/
                                    https://leetcode.com/problems/count-primes/solutions/153528/python3-99-112-ms-explained-the-sieve-of-eratosthenes-with-optimizations/
 NOTE:                              
                                    REMEMBER HOW SLICING NOTATION WORKS [K*K: N: K], NOT [K*K: K: N]                                   
                                    [0] * LEN([K*K: N: K]) VS [0] * ((N-1-K*K)//K)+1
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
        for k in range(2, int(n**0.5)+1):
        # while k <= math.sqrt(n):
            if numbersLeft[k] == 1:
                numbersLeft[ k*k: n: k] = [0] * (((n-1)-k*k)//k + 1)
# n = given from the parameter
# k = 2, 3, 4, .... <= int(n**0.5) or sqrt(n)
# (n-1-k*k)//k + 1
# (n-1)               # get total # of indicies for n (NON-inclusive)
#     -i*i            # shift to get # of slots in range of interest
#          //i        # get # of groups
#              + 1    # get # of slots
                
#   for example, if n = 11 
# numbersLeft[2*2:11:2]  = [0] * ((11-1-2*2)//2 + 1
#   11-1 = 10
#   [0 1 2 3 4 5 6 7 8 9]
#   shift to get the # of slots of interest
#   10 - 4 = 6
#   6 // 2 = 3
#   3 + 1 = 4
                
# numbersLeft[4:11:2]    = [0] * 4
# numbersLeft[4], numbersLeft[6], numbersLeft[8], numbersLeft[10] = 0, 0, 0, 0

#   VERY IMPORTANT TO REMEMBER TO INCREMENT K
            k += 1

#   return the result
        return sum(numbersLeft)

# why is strikes[ii:n:i] = [0] * ((n-1-ii)//i + 1)
# 3x faster than
# for j in range(i*i, n, i): strikes[j] = 0
    
# in principle they're basically the same, although 
# the range assignment is less memory efficient. 
# But in practice I think the list expression is faster 
# because Python is interpreted:

# range expression: the interpreter reevaluates the assignment 
# for every iteration of the loop. So if the loop iterates k times, 
# there are k interpreter evaluations.

# list comprehension: the range assignment is interpreted once, 
# and the list and range assignment is done by the runtime 
# which is usually implemented in C.

# So the list comprehension has k-1 fewer (so a LOT less) runs 
# of the interpreter, but at the cost of creating a big O(k) array 
# of 0's for the range assignment. The interpreter is slower 
# than memory allocation so the range assignment is faster

# I'd be careful about using tricks like this in an interview though. 
# A good interviewer would ask about the memory complexity 
# and peak memory use. A bad interviewer may just assume that 
# you don't know it's inefficient and 
# rate you lower without you ever knowing.
    
# So now we have that the time complexity of "crossing out" is:

# O(n) * O(1/2 + 1/3 + 1/5 + ... + 1/(last prime before n))
# = O(n) * O(log(log(n)))
# = O(nlog(log(n)))

# Thus, the nlog(log(n)) simply comes from the sum: 
# n/2 + n/3 + n/5 + ... + n/(last prime before n) 
# when we're crossing out numbers in the Sieve algorithm.