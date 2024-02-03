
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:26AM 02-01-2024
 *  Problem:                        number_bits_a_to_b (Zero)
 * 
 * @param {Integer} num1
 * @param {Integer} num2
 * @return {Integer}
 * 
 * 8 7 6 5 4 3 2 1 0
 * 1 0 0 1 1 0 1 0 1 <- n
 * 0 0 0 1 0 0 0 0 0
 * n & mask -> nonzero -> 1 bit
 *          -> else -> 0 bit
 * mask = 1 << i bits
 * set a bit
 * 0 0 0 0 0 1 0 0 0 || mask
 * mask = 1 << i bis
 * n = n | mask
 * clear a bit
 * 0 0 0 0 0 1 0 0 0            <- 1 << i
 * 1 1 1 1 1 0 1 1 1 && mask    <- ~(1 << i)
 * mask = 1 << i => ~(1 << i)
 * n = n & mask
 * 
 * 
 * question:    how many bits are needed to change from a to b
 * where
 * a =
 * 1 0 1 1 0 
 * and b = 
 * 1 1 0 1 1
 * ^
 * 0 1 1 0 1
 * 
 * now answer = 13
 * 1 1 0 1 -> 1
 * -> right shift
 * 0 1 1 0
 * 0 0 1 1 -> 1
 * 0 0 0 1 -> 1
 * because 13 is between 8 and 16
 * 0 0 0 0 -> O(log2n+1)
 */

#include <iostream>

class Solution
{
    public:
        int number_bits_needed_a_to_b(int num1, int num2)
        {

//********************************************************************************************************************
//  Step 1: XOR the two numbers to find the difference between the bits 
//********************************************************************************************************************

            int result = num1 ^ num2;
            int num_of_bits_needed = 0;

            while (result > 0)
            {
                if ((result & 1) == 1)
                {

//********************************************************************************************************************
//  Step 2: calculate the number of bits and add them to the sum 
//********************************************************************************************************************

                    num_of_bits_needed += 1;
                }

//********************************************************************************************************************
//  Step 3: iterate through the digits by RIGHT-SHIFTING 
//********************************************************************************************************************

                result >>= 1;
            }

//********************************************************************************************************************
//  Step 4: return the result 
//********************************************************************************************************************

            return num_of_bits_needed;
        }       
};

int main()
{
    //  128 64 32 16 8 4 2 0
    //  0   0  0  0  0 0 0 0

    Solution solution;
    int number1 = 32;
    int number2 = 31;

    std::cout << "The first number contains the value of " << number1 << "." << std::endl;
    std::cout << "The second number contains the value of " << number2 << "." << std::endl;
    std::cout << "The number of bits needed to convert number1 to number2 = " << solution.number_bits_needed_a_to_b(number1, number2) 
            << "." << std::endl;

    int number3 = 20;
    int number4 = 14;
    std::cout << "The third number contains the value of " << number3 << "." << std::endl;
    std::cout << "The fourth number contains the value of " << number4 << "." << std::endl;
    std::cout << "The number of bits needed to convert number3 to number4 = " << solution.number_bits_needed_a_to_b(number3, number4) 
            << "." << std::endl;

    int number5 = 14;
    int number6 = 20;
    std::cout << "The fifth number contains the value of " << number5 << "." << std::endl;
    std::cout << "The sixth number contains the value of " << number6 << "." << std::endl;
    std::cout << "The number of bits needed to convert number5 to number6 = " << solution.number_bits_needed_a_to_b(number5, number6) 
            << "." << std::endl;

    return 0;
}