
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:26PM 03-14-2024
 *  Problem:                        561. Array Partition (Easy)
 *  Reference:                      https://leetcode.com/problems/array-partition/description/
 *
 *  @func arrayPairSum
 *  @param { List of Integer } nums
 *  @return { Integer }
*/
//
//  561. Array Partition
//  Solved
//  Easy
//  Topics
//  Companies
//  Hint
//  Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) 
//  such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
//
//  Example 1:
//  Input: nums = [1,4,3,2]
//  Output: 4
//  Explanation: All possible pairings (ignoring the ordering of elements) are:
//  1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
//  2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
//  3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
//  So the maximum possible sum is 4.
//
//  Example 2:
//  Input: nums = [6,2,6,5,1,2]
//  Output: 9
//  Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
//
//  Constraints:
//  1 <= n <= 104
//  nums.length == 2 * n
//  -104 <= nums[i] <= 104
//  Hint 1
//  Obviously, brute force won't help here. Think of something else, take some example like 1,2,3,4.
//  Hint 2
//  How will you make pairs to get the result? There must be some pattern.
//  Hint 3
//  Did you observe that- Minimum element gets add into the result in sacrifice of maximum element.
//  Hint 4
//  Still won't able to find pairs? Sort the array and try to find the pattern.

import java.util.Arrays;

class Solution
{
    public int arrayPairSum( int[] nums )
    {
        Arrays.sort(nums);
        int maximized_sum = 0;

        for ( int i = 0; i < nums.length; i += 2)
        {
            maximized_sum += nums[i];
        }

        return maximized_sum;
    }
}

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();       

        int[] array1 = {3, 1, 2, 4};
        int[] array2 = {6,2,6,5,1,2};

        System.out.println("Maximized sum of array1 of " + Arrays.toString(array1) + " = " + solution.arrayPairSum(array1));
        System.out.println();
        System.out.println("Maximized sum of array2 of " + Arrays.toString(array2) + " = " + solution.arrayPairSum(array2));
    }
}