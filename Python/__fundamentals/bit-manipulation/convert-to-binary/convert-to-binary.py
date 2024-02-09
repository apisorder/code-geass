
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:02PM 02-08-2024
 *  Problem:                        Convert to Binary (Zero)
 *  @param {Solution} self
 *  @param {integer} number
 *  @return {String}
'''

class Solution:
    def convert_to_binary(self, number):

#********************************************************************************************************************
#  Step 1: create an empty string
#********************************************************************************************************************

        converted = ""

#********************************************************************************************************************
#  Step 2: while the number isn't 0
#********************************************************************************************************************

        while number != 0:

#********************************************************************************************************************
#  Step 3: pre-pend a "0" or "1" based on whether the number is even or odd to the result
#********************************************************************************************************************

            if (number & 1) == 0:
                converted = "0" + converted
            else:
                converted = "1" + converted
            
            number >>= 1

#********************************************************************************************************************
#  Step 4: return the result
#********************************************************************************************************************

        return converted
    
solution = Solution

#   64  32  16  8   4   2   0
#   0   0   1   0   1   0   0
#   1   0   1   0   0   1   0

number1 = 20
number2 = 82

print(solution.convert_to_binary(solution, number1))
print(solution.convert_to_binary(solution, number2))
