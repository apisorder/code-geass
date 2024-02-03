
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:18AM 02-01-2024
 *  Problem:                        Determine Number Is Even Or Odd (Zero)
 * @param {Integer} number
 * @return {String}
 */

#include <iostream>
#include <string>

class Solution
{
    public:
        std::string numberEvenOrOdd(int number)
        {

//********************************************************************************************************************
//  Step 1: since a even number will never have bit 0 set, AND the number with 1 will always be 0
//********************************************************************************************************************

            if ((number & 1) == 0)
            {
                return "even";
            }
            else
            {
                return "odd";
            }
        }
};

int main()
{
    Solution solution;
    int number1 = 128;
    int number2 = 7;

    std::cout << "The first number contains the value of " << number1 << " and is " 
        << solution.numberEvenOrOdd(number1) << std::endl;
    std::cout << "The second number contains the value of " << number2 << " and is " 
        << solution.numberEvenOrOdd(number2) << std::endl;

    return 0;
}