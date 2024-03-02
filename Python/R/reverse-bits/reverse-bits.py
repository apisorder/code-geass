
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  06:38PM 02-14-2024
 *  Problem:                        190. Reverse Bits (Easy)
 *  Reference:                      https://leetcode.com/problems/reverse-bits/description/
 *@param {Solution} self
 *@param {Integer} num
 *@return {Integer}

  NOTE:                             The approach is to preserve the bits we want to swap with the mask
                                    Then shift the intermediate result to the place we want to swap from
                                    And then OR the result to complete the swap
                                    i.e.
                                    AAAABBBB
                                    =>
                                    intermediate result 1 = AAAABBBB & 0xffff0000
                                    intermediate result 2 = AAAABBBB & 0x0000ffff
                                    intermediate result 1 = (AAAABBBB & 0xffff0000) >> 16
                                    intermediate result 2 = (AAAABBBB & 0x0000ffff) << 16
                                    swap done = intermediate result 1 | intermediate result 2
                                    And then we swap within the swapped partition, i.e. 16 -> 8 -> 4 -> 2 -> 1
                                    For a total of 5 passes
 '''

# 190. Reverse Bits
# Solved
# Easy
# Topics
# Companies
# Reverse bits of a given 32 bits unsigned integer.

# Note:

# Note that in some languages, such as Java, there is no unsigned integer type. 
# In this case, both input and output will be given as a signed integer type. 
# They should not affect your implementation, as the integer's internal binary representation 
# is the same, whether it is signed or unsigned.
# In Java, the compiler represents the signed integers using 2's complement notation. 
# Therefore, in Example 2 above, the input represents the signed integer -3 
# and the output represents the signed integer -1073741825.
 

# Example 1:

# Input: n = 00000010100101000001111010011100
# Output:    964176192 (00111001011110000010100101000000)
# Explanation: The input binary string 00000010100101000001111010011100 
# represents the unsigned integer 43261596, so return 964176192 
# which its binary representation is 00111001011110000010100101000000.
# Example 2:

# Input: n = 11111111111111111111111111111101
# Output:   3221225471 (10111111111111111111111111111111)
# Explanation: The input binary string 11111111111111111111111111111101 
# represents the unsigned integer 4294967293, so return 3221225471 
# which its binary representation is 10111111111111111111111111111111.
 

# Constraints:

# The input must be a binary string of length 32
 

# Follow up: If this function is called many times, how would you optimize it?

# Seen this question in a real interview before?
# 1/4
# Yes
# No
# Accepted
# 750.4K
# Submissions
# 1.3M
# Acceptance Rate
# 57.6%

class Solution:
    def reverseBits(self, num):

#********************************************************************************************************************
#  Step 1: swap the left 16 bits ith the right 16 bits
#********************************************************************************************************************        

        num = ((num & 0xffff0000) >> 16) | ((num & 0x0000ffff) << 16)

#********************************************************************************************************************
#  Step 2: swap the first/third 8 bits with the second/fourth 8 bits
#********************************************************************************************************************        

        num = ((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8)

#********************************************************************************************************************
#  Step 3: swap the 1st/3rd/5th/7th 4 bits with the 2nd/4th/6th/8th 4 bits
#********************************************************************************************************************        

        num = ((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4)

#********************************************************************************************************************
#  Step 4: swap the 1/3/5/7/9/11/13/15 2 bits with the 2/4/6/8/10/12/14/16 2 bits
#********************************************************************************************************************        

        num = ((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2)

#********************************************************************************************************************
#  Step 5: swap all odd bits with even bits
#********************************************************************************************************************        

        num = ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1)

        return num 

solution = Solution()

number1 = 43261596
number2 = 4294967293
# expected1 = 964176192
# expected2 = 3221225471

print(f'{number1} becomes {solution.reverseBits(number1)}, after having all of its bits reversed')
print(f'{number2} becomes {solution.reverseBits(number2)}, after having all of its bits reversed')
