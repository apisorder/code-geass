
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  04:35AM 03-15-2024
//  *  Problem:                        561. Array Partition (Easy)
//  *  Reference:                      https://leetcode.com/problems/array-partition/description/
//                                
//  @param { Vector of Integer } nums 
//  @return { Integer }
//
//  561. Array Partition
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

#include <iostream>

#include <vector>
//  needed for std::vector; remember to declare vector as std::vector

#include <algorithm>
//  needed for std::sort; remember to write sort as std::sort

class Solution 
{
    public:
        int arrayPairSum(std::vector<int>& nums) 
        {
            //********************************************************************************************************************
            //  Step 1: sort the array
            //********************************************************************************************************************
            std::sort(nums.begin(), nums.end());

            //********************************************************************************************************************
            //  Step 2: declare variable to store the sum
            //********************************************************************************************************************
            int maximized_result = 0;

            //********************************************************************************************************************
            //  Step 3: add all the smaller value of the each pair
            //********************************************************************************************************************
            for (int i = 0; i < nums.size(); i += 2)
            {
                maximized_result += nums[i];
            }

            //********************************************************************************************************************
            //  Step 4: return the result
            //********************************************************************************************************************
            return maximized_result;
        }
};

int main()
{
    Solution solution;

    std::vector<int> array1 = {1,4,3,2};
    std::vector<int> array2 = {6,2,6,5,1,2};

    int result1 = solution.arrayPairSum(array1);
    int result2 = solution.arrayPairSum(array2);

    std::cout << "Maximized result of array1 of [";

    //********************************************************************************************************************
    //  printing the contents of the vector
    //********************************************************************************************************************
    for (int i : array1 )
    //  same as for ( int i = 0; i < array1.size(); i++)
    {
        std::cout << i << ", ";
        //  same as std::cout << array1[i] << ", ";
    }

    std::cout << "] = " << result1 << " \n";
    std::cout << "Maximized result of array2 of [";

    //********************************************************************************************************************
    //  printing the contents of the vector
    //********************************************************************************************************************
    for (int i : array2 )
    {
        std::cout << i << ", ";
    }
    std::cout << "] = " << result2 << " \n";

    return 0;
}