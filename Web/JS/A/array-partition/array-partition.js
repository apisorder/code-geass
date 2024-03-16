
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  06:23PM 03-15-2024
 *  Problem:                        561. Array Partition (Easy)
 *  Reference:                      https://leetcode.com/problems/array-partition/description/
 *
 *  @param { Array of Integer } nums
 *  @return { Integer }
*/
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
//
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
//  Seen this question in a real interview before?
//  1/4
//  Yes
//  No
//  Accepted
//  461.8K
//  Submissions
//  588.3K
//  Acceptance Rate
//  78.5%

let arrayPairSum = function(nums) 
{
    nums.sort(function(a, b){ return a-b });

    let maximized_sum = 0;

    for (let i = 0; i < nums.length; i += 2)
    {
        maximized_sum += nums[i];
    }
    return maximized_sum;
};

let arr1 = [1,4,3,2];
let arr2 = [6,2,6,5,1,2];

let result1 = arrayPairSum(arr1);
let result2 = arrayPairSum(arr2);

console.log( `Maximized sum of array1 of [${arr1}] = ${result1}`)
console.log( `Maximized sum of array2 of [${arr2}] = ${result2}`)