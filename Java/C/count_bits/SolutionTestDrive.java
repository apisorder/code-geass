
//
// *  Programmer:                     Jeff C. Cheng
// *  Last modified:                  10:01PM 02-07-2024
// *  Problem:                        338. Counting Bits (Easy)
// *  Reference:                      https://leetcode.com/problems/counting-bits/description/ 
//                                    https://leetcode.com/problems/counting-bits/solutions/1808002/a-very-very-easy-to-go-explanation/
// @param {Integer} n
// @return {Array of Integer}

// 338. Counting Bits
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an integer n, return an array ans of length n + 1 such that 
// for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
 

// Constraints:

// 0 <= n <= 105
 

// Follow up:

// It is very easy to come up with a solution with a runtime of O(n log n). 
// Can you do it in linear time O(n) and possibly in a single pass?
// Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
// Seen this question in a real interview before?
// 1/4
// Yes
// No
// Accepted
// 1M
// Submissions
// 1.3M
// Acceptance Rate
// 77.9% 

import java.util.Arrays;

class Solution 
{

// Very concise and insightful solution, and here I am gonna simply 
// explain why this formula works.

// When it comes to even numbers, i.e, 2,4,6,8, their binary should be like 
// '10', '100', '110', '1000' so one notable difference is their unit digit is always 0, 
// which means when you call >> 1- shift one bit rightwards and also means 
// dividing by 2- would cause no change to the count of '1' in the binary string.
    
// Vice versa, when you meet odd numbers, shifting one bit rightwards always eliminates 
// one '1' digit from original binary string, that is why we should "compensate" 
// one '1' character to the count.
    
// To sum up, when you meet even number the count of '1's is always the same as 
// its half number, on the other hand, remember to plus one to the odds' half number.

    public int[] countBits(int n)
    {
        int[] dp = new int[ n+1 ];

        for (int i = 0; i <= n; i++)
        {
            dp[i] = dp[i >> 1] + (i % 2);
        }
            
        return dp;
    }

//********************************************************************************************************************
//  Step 1 ALT: create helper function to count the ones in each number
//********************************************************************************************************************

// @param {Integer} num
// @param {Array of Integer} memo
// @return {Array of Integer}
    int countOnes(int num, int[] memo)
    {

//********************************************************************************************************************
//  Step 2 ALT: base case
//********************************************************************************************************************
        
        if (num == 0 || num == 1)
        {
            return num;
        }

//********************************************************************************************************************
//  Step 3 ALT: use cache to decrease time complexity
//********************************************************************************************************************
        
        if (memo[num] > 0)
        {
            return memo[num];
        }

//********************************************************************************************************************
//  Step 4 ALT: not in the cache, so perform calculation based on whether the number is even or odd; put in cache; return
//********************************************************************************************************************
        
        if ((num & 1) == 0)
        {
            memo[num] = countOnes(num >> 1, memo);
        }
        else
        {
            memo[num] = 1 + countOnes(num >> 1, memo);
        }
        return memo[num];
    }

// @param {Integer} n
// @return {Array of Integer}
    public int[] countBitsRecursive(int n) 
    {

//********************************************************************************************************************
//  Step 5 ALT: create an array to store the number of bits for each number
//********************************************************************************************************************
        
        int[] results = new int[ n+1 ];

        for (int i = 0; i <= n; i++)
        {

//********************************************************************************************************************
//  Step 6 ALT: calculate the result
//********************************************************************************************************************
            
            results[i] = countOnes(i, results);
        }

//********************************************************************************************************************
//  Step 7 ALT: return the result
//********************************************************************************************************************
        
        return results;
    }
}
class SolutionTestDrive
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        int input = 5;
        int[] result = solution.countBitsRecursive(input);

        int [] result2 = solution.countBits((input));

        System.out.println(Arrays.toString(result));
        System.out.println(Arrays.toString(result2));
    }
};