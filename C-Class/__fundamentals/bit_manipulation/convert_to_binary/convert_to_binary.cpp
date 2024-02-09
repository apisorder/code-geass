
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:40PM 02-08-2024
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
                if ((num & 1) == 0)
                {
                    converted = "0" + converted;
                }
                else
                {
                    converted = "1" + converted;
                }

                num /= 2;
            }
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