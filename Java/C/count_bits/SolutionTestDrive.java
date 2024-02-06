
//
// *  Programmer:                     Jeff C. Cheng
// *  Last modified:                  08:40PM 02-04-2024
// *  Problem:                        338. Counting Bits (Easy)
// *  Reference:                      https://leetcode.com/problems/counting-bits/description/ 
//                                    https://leetcode.com/problems/counting-bits/solutions/1808002/a-very-very-easy-to-go-explanation/
//

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

class Solution {

//********************************************************************************************************************
//  Step 1: create helper function to count the ones in each number
//********************************************************************************************************************
    
    int countOnes(int num, int[] memo)
    {

//********************************************************************************************************************
//  Step 2: base case
//********************************************************************************************************************
        
        if (num == 0 || num == 1)
        {
            return num;
        }

//********************************************************************************************************************
//  Step 3: use cache to decrease time complexity
//********************************************************************************************************************
        
        if (memo[num] > 0)
        {
            return memo[num];
        }

//********************************************************************************************************************
//  Step 4: not in the cache, so perform calculation based on whether the number is even or odd; put in cache; return
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

    public int[] countBits(int n) 
    {

//********************************************************************************************************************
//  Step 5: create an array to store the number of bits for each number
//********************************************************************************************************************
        
        int[] results = new int[ n+1 ];

        for (int i = 0; i <= n; i++)
        {

//********************************************************************************************************************
//  Step 6: calculate the result
//********************************************************************************************************************
            
            results[i] = countOnes(i, results);
        }

//********************************************************************************************************************
//  Step 7: return the result
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
        int[] result = solution.countBits(input);

        System.out.println(Arrays.toString(result));
    }
};