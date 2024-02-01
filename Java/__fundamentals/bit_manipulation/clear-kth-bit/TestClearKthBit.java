
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:11PM 1-29-2024
 *  Problem:                        Clear Kth Bit (Zero)
 */

class Solution
{
    public int clearKthBit(int num, int kth_bit)
    {
        return (num & (~(1 << kth_bit)));
    }
};

class TestClearKthBit
{
    public static void main(String[] args)
    {
        //  remember to use the new keyword
        Solution solution = new Solution();
        //  32  16  8   4   2   0
        //  0   0   0   1   0   1
        //  0   1   0   1   0   0
        int number1 = 5;
        int number2 = 20;
        int kth_bit = 2;

        System.out.println("The first number contains the value of " + number1 +".");
        int result = solution.clearKthBit(number1, kth_bit);
        System.out.println("With bit " + kth_bit + " cleared, the new value is " + result + ".");

        System.out.println("The second number contains the value of " + number2 +".");
        result = solution.clearKthBit(number2, kth_bit);
        System.out.println("With bit " + kth_bit + " cleared, the new value is " + result + ".");
    }
};


