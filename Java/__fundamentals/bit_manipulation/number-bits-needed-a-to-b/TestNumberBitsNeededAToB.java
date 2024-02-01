
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:03PM 1-31-2024
 *  Problem:                        Number Of Bits Needed A To B (Zero)
 */

class Solution
{
public int NumberBitsNeededAToB(int num1, int num2)
    {
        int result = num1 ^ num2;
        int numberOfBitsNeeded = 0;

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
 
 
 