
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  5:49PM 1-15-2024
 *  Problem:                        0. Number of Digit Nine (No Difficulty)
 *  Reference:                      https://leetcode.com/problems/number-of-digit-nine/description/
 NOTE:                              
                                    REMEMBER (LARGER)//10*MULTIPLIER + (LARGER % MULTIPLIER == 9)*(SMALLER+1)
'''

class Solution:
    def countDigitNine(self, n):

        numOfNines = 0
        multiplier = 1
        
        while multiplier <= n:
            larger = n // multiplier
            smaller = n % multiplier
            
            numOfNines += larger//10*multiplier + (larger % 10 == 9)*(smaller+1)
            
            multiplier *= 10
            
        return numOfNines
    
solution = Solution
n = 10
print(solution.countDigitNine(solution, n))
n = 19
print(solution.countDigitNine(solution, n))
n = 29
print(solution.countDigitNine(solution, n))
n = 39
print(solution.countDigitNine(solution, n))
n = 49
print(solution.countDigitNine(solution, n))
n = 59
print(solution.countDigitNine(solution, n))
n = 69
print(solution.countDigitNine(solution, n))
n = 79
print(solution.countDigitNine(solution, n))
n = 89
print(solution.countDigitNine(solution, n))
n = 99
print(solution.countDigitNine(solution, n))
n = 100
print(solution.countDigitNine(solution, n))
n = 109
print(solution.countDigitNine(solution, n))

