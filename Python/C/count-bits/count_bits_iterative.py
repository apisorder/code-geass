
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:24PM 02-07-2024
 *  Problem:                        338. Counting Bits (Easy)
 *  Reference:                      https://leetcode.com/problems/counting-bits/description/ 
                                    https://leetcode.com/problems/counting-bits/solutions/1808002/a-very-very-easy-to-go-explanation/
 *@param {Solution} self
 *@param {Integer} n
 *@return {Array of Integer}                          
'''

# 338. Counting Bits
# Solved
# Easy
# Topics
# Companies
# Hint
# Given an integer n, return an array ans of length n + 1 such that
# for each i (0 <= i <= n), ans[i] is the number of 1's 
# in the binary representation of i.

 

# Example 1:

# Input: n = 2
# Output: [0,1,1]
# Explanation:
# 0 --> 0
# 1 --> 1
# 2 --> 10
# Example 2:

# Input: n = 5
# Output: [0,1,1,2,1,2]
# Explanation:
# 0 --> 0
# 1 --> 1
# 2 --> 10
# 3 --> 11
# 4 --> 100
# 5 --> 101
 

# Constraints:

# 0 <= n <= 105
 

# Follow up:

# It is very easy to come up with a solution with a runtime of O(n log n). 
# Can you do it in linear time O(n) and possibly in a single pass?
# Can you do it without using any built-in function 
# (i.e., like __builtin_popcount in C++)?
# Seen this question in a real interview before?
# 1/4
# Yes
# No
# Accepted
# 1M
# Submissions
# 1.3M
# Acceptance Rate
# 77.9%

class Solution:
    def countBits(self, n):

#********************************************************************************************************************
#  Step 1: create an array to store the number of bits for each number
#********************************************************************************************************************

        dp = [0] * (n+1)

#********************************************************************************************************************
#  Step 2: iterate through each number
#********************************************************************************************************************

        for i in range(n+1):

#********************************************************************************************************************
#  Step 3: calculate each entry and store the result
#********************************************************************************************************************

            dp[i] = dp[i >> 1] + i % 2

#********************************************************************************************************************
#  Step 4: return the result
#********************************************************************************************************************

        return dp
    
solution = Solution()
num = 5
print(solution.countBits(num))