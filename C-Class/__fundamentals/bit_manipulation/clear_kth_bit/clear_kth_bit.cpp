
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:10PM 1-27-2024
 *  Problem:                        Clear Kth Bit (Zero)
 */

#include <iostream>

class Solution
{
    public:
        int clear_kth_bit(int *num, int kth_bit)
        {
            return (*num & (~(1 << kth_bit)));
        }
};

int main()
{
    //  8 4 2 0
    //  1 0 0 0
    Solution solution;

    int number1 = 14;
    int number2 = 10;
    int kth_bit_1 = 2;
    int kth_bit_2 = 1;

    std::cout << "The first number contains the value of " << number1 << " and after clearing bit "
                << kth_bit_1 << ", it becomes " << solution.clear_kth_bit(&number1, kth_bit_1) << std::endl;

    std::cout << "The second number contains the value of " << number2 << " and after clearing bit "
                << kth_bit_2 << ", it becomes " << solution.clear_kth_bit(&number2, kth_bit_2) << std::endl;

    return 0;
}