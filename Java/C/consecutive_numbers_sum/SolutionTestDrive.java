
//
// *  Programmer:                     Jeff C. Cheng
// *  Last modified:                  10:28PM 02-05-2024
// *  Problem:                        829. Consecutive Numbers Sum (Hard)
// *  Reference:                      https://leetcode.com/problems/consecutive-numbers-sum/description/
//                                    https://leetcode.com/problems/consecutive-numbers-sum/solutions/129015/5-lines-c-solution-with-detailed-mathematical-explanation/
// NOTE:                              
//                                    REMEMBER WHAT K MEANS
//                                    REMEMBER WHAT RESULT SHOULD INIT TO 
//
// @param {Integer} n
// @return {Integer}

// 829. Consecutive Numbers Sum
// Solved
// Hard
// Topics
// Companies
// Given an integer n, return the number of ways you can write n as the sum 
// of consecutive positive integers.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 = 2 + 3
// Example 2:

// Input: n = 9
// Output: 3
// Explanation: 9 = 4 + 5 = 2 + 3 + 4
// Example 3:

// Input: n = 15
// Output: 4
// Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 

// Constraints:

// 1 <= n <= 109
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Accepted
// 84.4K
// Submissions
// 202.1K
// Acceptance Rate
// 41.8%

// import java.lang.Math;

// class Solution {
//     public int consecutiveNumbersSum(int n) 
//     {
//         int numOfWays = 1;

//         for (int k = 2; k < Math.sqrt(2*n); k++)
//         {
//             if ((n - k*(k-1)/2) % k == 0)
//             {
//                 numOfWays += 1;
//             }
//         }
//         return numOfWays;
//     }
// }

import java.lang.Math;
class Solution {
    public int consecutiveNumbersSum(int n) 
    {

//********************************************************************************************************************
//  Step 1: the number itself is a sequence of k, where k = 1
//********************************************************************************************************************
        
        int numOfWays = 1;

//********************************************************************************************************************
//  Step 2: from k between 2 and square root of 2xn
//********************************************************************************************************************
        
        for (int k = 2; k < Math.sqrt(2*n); k++)
        {

//********************************************************************************************************************
//  Step 3: if the equation is a multiple of k
//********************************************************************************************************************
            
            if ((n - k*(k-1)/2 ) % k == 0)
            {

//********************************************************************************************************************
//  Step 4: one more solution has been found
//********************************************************************************************************************
                
                numOfWays += 1;
            }
        }

//********************************************************************************************************************
//  Step 5: return the result
//********************************************************************************************************************
        
        return numOfWays;
    }
}

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        //  Example 1:

        //  Input: n = 5
        //  Output: 2
        
        //  Example 2:
        //  Input: n = 9
        //  Output: 3
        
        //   Example 3:
        //  Input: n = 15
        //  Output: 4

        int number1 = 5;
        int number2 = 9;
        int number3 = 15;
        
        System.out.println(solution.consecutiveNumbersSum(number1));
        System.out.println(solution.consecutiveNumbersSum(number2));
        System.out.println(solution.consecutiveNumbersSum(number3));
    }
}