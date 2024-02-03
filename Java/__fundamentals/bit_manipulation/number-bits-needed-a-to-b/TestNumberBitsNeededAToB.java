
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  08:28AM 02-02-2024
 *  Problem:                        Number Of Bits Needed A To B (Zero)
 * @param {Integer} num1
 * @param {Integer} num1
 * @return {Integer}
 */

class Solution
{
public int NumberBitsNeededAToB(int num1, int num2)
    {

//********************************************************************************************************************
//  Step 1: XOR the two numbers to get a number of their differences 
//********************************************************************************************************************
        
        int result = num1 ^ num2;
        int numberOfBitsNeeded = 0;

//********************************************************************************************************************
//  Step 2: calculate the number of bits where the two numbers are different
//********************************************************************************************************************
        
        while (result != 0)
        {
            numberOfBitsNeeded += (result & 1);
            result >>= 1;
        }
        return numberOfBitsNeeded;
    }
};
 
class TestNumberBitsNeededAToB
{
    public static void main(String[] args)
    {
    //  remember to use the new keyword
        Solution solution = new Solution();
        //  32  16  8   4   2   0
        //  0   0   0   1   0   1
        //  0   1   0   1   0   0
        int number1 = 6;
        int number2 = 8;

        int number3 = 28;
        int number4 = 32;

        System.out.println("The first number contains the value of " + number1 +".");
        System.out.println("The second number contains the value of " + number2 +".");
        System.out.println("The number of bits needed to convert the numbers = " + solution.NumberBitsNeededAToB(number1, number2) + ".");
        
        System.out.println("The third number contains the value of " + number3 +".");
        System.out.println("The fourth number contains the value of " + number4 +".");
        System.out.println("The number of bits needed to convert the numbers = " + solution.NumberBitsNeededAToB(number3, number4) + ".");
    }
};
 
 
 