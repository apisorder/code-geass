
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:14PM 1-22-2024
 *  Problem:                        2. Swap Two Numbers (Zero)
*/

#include <iostream>

class Solution
{
    public:
        void swapTwoNumbers(int *a, int *b)
        {
            *a = *a ^ *b;
            *b = *a ^ *b;
            *a = *a ^ *b; 
        }
};

int main()
{
    Solution solution;
    int number1 = 11;
    int number2 = 7;

    std::cout << "The first number has the value of " << number1 << std::endl;
    std::cout << "The first number has the value of " << number2 << std::endl;

    solution.swapTwoNumbers( &number1, &number2 );
    
    std::cout << "The first number has the value of " << number1 << std::endl;
    std::cout << "The first number has the value of " << number2 << std::endl;

    return 0;
}