
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:19PM 1-22-2024
 *  Problem:                        Number Even Or Odd (Zero)
*/

class Solution
{
    public String numberEvenOrOdd(int number)
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
}

class TestNumberEvenOrOdd
{
    public static void main(String[] args)
    {
        // Test Case:
        // Input: number = 5
        // Output = "odd"
        // Input: number = 12
        // Output = "even"
        
        Solution solution = new Solution();       
        int number1 = 5;
        int number2 = 12;

        System.out.println("The number " + number1 + " is " + solution.numberEvenOrOdd(number1) + ".");
        System.out.println("The number " + number2 + " is " + solution.numberEvenOrOdd(number2) + "."); 
    }
}