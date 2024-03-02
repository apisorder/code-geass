
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  12:53AM 02-11-2024
 *  Problem:                        Number of Bits Which Are One (Zero)
 *  @param {Integer} num
 *  @return {String}
 *  NOTE:                           This approach is faster with time complexity of O(number of set bits)
 *                                  than time complexity of O(log n), where we have to iterate through
 *                                  each and every bit of a number
 *                                  This is because n & (n-1) always clears the rightmost set bit
 */

 class Solution
 {
     public int NumberBitOnes(int num)
     {
        int sum = 0;
        while (num > 0)
        {
            num = num & (num-1);
            sum += 1;
        }
        return sum;
     }
 };
 
 class TestNumberBitOnes
 {
     public static void main(String[] args)
     {
        //  remember to use the new keyword
        Solution solution = new Solution();

        //  64  32  16  8   4   2   0
        //  1   0   0   1   0   0   0
        //  0   0   1   0   1   0   0

        int number1 = 72;
        int number2 = 20;

        System.out.println(number1 + " has " + solution.NumberBitOnes(number1) + " bit(s), which are 1.");
        System.out.println(number2 + " has " + solution.NumberBitOnes(number2) + " bit(s), which are 1.");
    }
 };
 
 
 