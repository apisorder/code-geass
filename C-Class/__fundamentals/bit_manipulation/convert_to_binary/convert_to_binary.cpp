
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  07:58PM 03-24-2024
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
            std::string converted = "";

            while (num != 0)
            {
                converted = (num & 1) == 0 ? ("0" + converted) : ("1" + converted);
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