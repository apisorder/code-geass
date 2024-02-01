
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:15PM 1-22-2024
 *  Problem:                        Determine Number Is Even Or Odd (Zero)
 */

#include <iostream>
#include <string>

class Solution
{
    public:
        std::string numberEvenOrOdd(int number)
        {
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