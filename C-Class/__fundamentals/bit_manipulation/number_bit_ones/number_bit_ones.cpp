
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:57AM 02-11-2024
 *  Problem:                        Number of Bits Which Are One (Zero)
 *  @param {Integer} num
 *  @return {Integer}
 */

#include <iostream>

class Solution
{
    public:
        int number_of_bit_ones(int num)
        {
            int sum = 0;

            while (num > 0)
            {

//********************************************************************************************************************
//  Step 1: while number is not 0, count the number of 1's
//********************************************************************************************************************

                num = num & (num-1);
                sum++;
            }

            return sum;
        }
};

int main()
{
    //  8 4 2 0
    //  1 0 0 0
    //  1 0 1 0
    Solution solution;

    int number1 = 8;
    int number2 = 10;

    std::cout << number1 << " has " << solution.number_of_bit_ones(number1) << " bit(s) which are 1." << std::endl;
    std::cout << number2 << " has " << solution.number_of_bit_ones(number2) << " bit(s) which are 1." << std::endl;

    return 0;
}