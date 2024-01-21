
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  5:58PM 1-6-2024
 *  Problem:                        223. Number of Digit One (Hard)
 *  Reference:                      https://leetcode.com/problems/number-of-digit-one/description/
                                    https://leetcode.com/problems/number-of-digit-one/solutions/64382/java-python-one-pass-solution-easy-to-understand/
 NOTE:                              
                                    REMEMBER (LARGER+8)//10*MULTIPLIER + (LARGER % MULTIPLIER == 1)*(SMALLER+1)
'''

# 233. Number of Digit One
# Hard
# 1.4K
# 1.4K
# Companies
# Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

# Example 1:

# Input: n = 13
# Output: 6
# Example 2:

# Input: n = 0
# Output: 0
 

# Constraints:

# 0 <= n <= 109
# Accepted
# 86.1K
# Submissions
# 251.2K
# Acceptance Rate
# 34.3%

class Solution:
    def countDigitOne(self, n):
#   to figure out the number of digit 1's
#   we need to consider 3 cases
#   let's say we are considering the 1000's position
#   the possibilities are as follows:
#   (for ease of understanding, we use actual numbers)
#   Case 1 (always included): 456D123 where D = 0
#       1000-1999 (1000 [of digit 1])
#        11000-11999 (1000)
#        21000-21999 (1000)
#       ...
#       4551000-4551999 (1000) -> naturally, 4561000-4561999 are excluded
#       => 456 * 1000 (the signficiance of the digit) (SUM 1)      
#   Case 2 (in addition to Case 1, binary choice): 456D123 where D = 1
#       (SUM 1) + 1000-1123 (so whatever the reminder is, i.e. number mod the [significance of the digit])
#       AND PLUS 1 (REALLY IMPORTANT, i.e. 1356 -> 356 + 1000, since it begins at 1000)
#   Case 3 (in addition to Case 1, binary choice): 456D123 where D > 1 (2 to 9)
#       (SUM 1) + (1000) => because 4561000-4561999 (1000) would have been included

        # 456D123 +8
        
        # 4560123 +8 => 456 8 123
        #             => % 10 == 0 
        
        # 4561123 +8 => 456 9 123
        #             => % 10 == 1 => + ABC
        
        # 4562123 +8 => 457 0 123
        #             => % 10 == 2
                    
        # 4563123 +8 => 457 1 123
        #             => % 10 == 3
                    
        # 4564123 +8 => 457 2 123
        #             => % 10 == 4
                    
        # 4565123 +8 => 457 3 123
        #             => % 10 == 5
                    
        # 4566123 +8 => 457 4 123
        #             => % 10 == 6
                    
        # 4567123 +8 => 457 5 123
        #             => % 10 == 7
                    
        # 4568123 +8 => 457 6 123
        #             => % 10 == 8
                    
        # 4569123 +8 => 457 7 123
        #             => % 10 == 9
        
        numOfOnes = 0
        multiplier = 1

        while multiplier <= n:
            larger = n // multiplier
            smaller = n % multiplier

            numOfOnes += (larger + 8)//10*multiplier + (larger%10 == 1)*(smaller+1)
        
            multiplier *= 10

        return numOfOnes