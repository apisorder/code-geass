
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:27PM 02-02-2024
 *  Problem:                        Swap Two Numbers (Zero)
 *  @param {Pointer to Integer} a
 *  @param {Pointer to Integer} b
 *  @return {Void}
*/

#include <iostream>

class Solution
{
    public:
        void swapTwoNumbers(int *a, int *b)
        {

//********************************************************************************************************************
//  Step 1: storing parts of a and parts of b in a
//********************************************************************************************************************

            *a = *a ^ *b;

//********************************************************************************************************************
//  Step 2: storing only parts of a in b, i.e. parts of a + parts of b + all of b = only a
//********************************************************************************************************************

            *b = *a ^ *b;

//********************************************************************************************************************
//  Step 3: storing only parts of b in a, i.e. parts of a + parts of b + all of a = only b 
//********************************************************************************************************************

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