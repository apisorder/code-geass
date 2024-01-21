
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  5:58PM 1-6-2024
 *  Problem:                        223. Number of Digit One (Hard)
 *  Reference:                      https://leetcode.com/problems/number-of-digit-one/description/
                                    https://leetcode.com/problems/number-of-digit-one/solutions/64382/java-python-one-pass-solution-easy-to-understand/
 NOTE:                              
                                    REMEMBER THE PLUS 1 (1000 + XYZ) for D == 1
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
        
#   to calculate the significance of the digit
        multiplier = 1
        sum = 0

#   to retain the original number value
        m = n
#   while n is greater than 0
        while m:
#   get D
            digit = m % 10
#   get the number to the left of D
            m = m // 10
#   Case 1
            sum = sum + m * multiplier
#   Case 2
            if digit == 1:
                sum = sum + (n % multiplier) + 1
#   OR Case 3
            if digit > 1:
                sum = sum + multiplier
#   get the next higher significiant digit
            multiplier *= 10

        return sum