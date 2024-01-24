
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  3:20PM 1-22-2024
 *  Problem:                        Swap Two Numbers (Zero)
 *  Reference:                      https://stackoverflow.com/questions/2393906/java-method-to-swap-primitives/20600020#20600020
 *                                  https://docs.oracle.com/javase/specs/jls/se8/html/jls-15.html#jls-15.7.4
 *  NOTE:                           
 *                                  y = swap(x, x=y)
 */

class Solution
{
    public int swapTwoNumbers(int a, int b)
    {
        return a;
    }
}

class TestSwapTwoNumbers
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();       
        int number1 = 5;
        int number2 = 12;
        System.out.println("The first number contains the value of " + number1 +".");
        System.out.println("The second number contains the value of " + number2 +".");

        number2 = solution.swapTwoNumbers(number1, number1=number2);
        
        System.out.println("The first number contains the value of " + number1 +".");
        System.out.println("The second number contains the value of " + number2 +".");
    }
}