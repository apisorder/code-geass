
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:52PM 02-08-2024
 *  Problem:                        Convert to Binary (Zero)
 *  @param {Integer} number
 *  @return {Strng}
 */

#include <iostream>
#include <string>

class Solution
{
    public:
    
        std::string convert_to_binary(int num)
        {

//********************************************************************************************************************
//  Step 1: create an empty string
//********************************************************************************************************************

            std::string converted = "";

//********************************************************************************************************************
//  Step 2: while the number isn't 0
//********************************************************************************************************************

            while (num != 0)
            {

//********************************************************************************************************************
//  Step 3: pre-pend a "0" or "1" based on whether the number is even or odd to the result
//********************************************************************************************************************

                if ((num & 1) == 0)
                {
                    converted = "0" + converted;
                }
                else
                {
                    converted = "1" + converted;
                }

                num >>= 1;
            }

//********************************************************************************************************************
//  Step 4: return the result
//********************************************************************************************************************

            return converted;
        }
};

int main()
{
    //  8 4 2 0
    //  1 0 0 0
    Solution solution;

    int number1 = 12;
    int number2 = 13;

    std::cout << solution.convert_to_binary(number1) << std::endl;
    std::cout << solution.convert_to_binary(number2) << std::endl;

    return 0;
}