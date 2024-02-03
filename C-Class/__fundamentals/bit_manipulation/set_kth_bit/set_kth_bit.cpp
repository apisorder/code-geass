
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:14AM 02-01-2024
 *  Problem:                        Set Kth Bit (Zero)
 *  @param {Pointer to Integer} num
 *  @param {Integer} kth_bit
 *  @return {Integer}
 */

#include <iostream>

class Solution
{
    public:
        int set_kth_bit(int *num, int kth_bit)
        {

//********************************************************************************************************************
//  Step 1: OR the number with 1 LEFT-SHIFTED k bits will always set that bit in the number
//********************************************************************************************************************

            return (*num | (1 << kth_bit));
        }
};

int main()
{
    //  8 4 2 0
    //  1 0 0 0
    Solution solution;

    int number1 = 8;
    int number2 = 10;
    int kth_bit_1 = 2;
    int kth_bit_2 = 2;

    std::cout << "The first number contains the value of " << number1 << " and after setting bit "
                << kth_bit_1 << ", it becomes " << solution.set_kth_bit(&number1, kth_bit_1) << std::endl;

    std::cout << "The second number contains the value of " << number2 << " and after setting bit "
                << kth_bit_2 << ", it becomes " << solution.set_kth_bit(&number2, kth_bit_2) << std::endl;

    return 0;
}