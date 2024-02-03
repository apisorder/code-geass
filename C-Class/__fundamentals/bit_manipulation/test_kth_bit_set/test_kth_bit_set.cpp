
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:27AM 02-03-2024
 *  Problem:                        Test If Kth Bit Is Set (Zero)
 *  @param {Integer} number
 *  @param {Integer} kth_bit
 *  @return {Boolean}
 */

#include <iostream>

class Solution
{
    public:
        bool test_kth_bit_set(int num, int kth_bit)
        {

//********************************************************************************************************************
//  Step 1: LEFT-SHIFT 1 k bits and AND it with the number will test whether kth bit is set (1) or not (0)
//********************************************************************************************************************

            return (num & (1 << kth_bit));
        }
};

int main()
{
    Solution solution;

    //  64  32  16  8   4   2   0
    //  1   0   0   1   0   0   0
    //  0   0   1   0   1   0   0

    int number1 = 72;
    int number2 = 20;
    int kthBit1 = 3;
    int kthBit2 = 6;

    std::cout << "First number has value of " << number1 << "." << std::endl; 
    std::cout << "Its bit " << kthBit1 << " has the value of " << (solution.test_kth_bit_set(number1, kthBit1) ? 1: 0) << std::endl;
    std::cout << "Second number has value of " << number2 << "." << std::endl; 
    std::cout << "Its bit " << kthBit2 << " has the value of " << (solution.test_kth_bit_set(number2, kthBit2) ? 1: 0) << std::endl;

    return 0;
}