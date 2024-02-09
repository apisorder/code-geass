

/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  11:59AM 02-03-2024
 *  Problem:                        Convert to Binary (Zero)
 *  @param {Integer} num
 *  @return {String}
 */

 class Solution
 {
     public int ConvertToBinary(int num)
     {

//********************************************************************************************************************
//  Step 1: LEFT-SHIFT 1 k bits and AND it with the number will test whether kth bit is set (1) or not (0)
//********************************************************************************************************************
        // System.out.println(num & (1 << kth_bit));
        // System.out.println((num & (1 << kth_bit)) == 1);
        // System.out.println((num & (1 << kth_bit)) == 0);

        String converted = new String();

        while (num != 0)
        {
            if ((num & 1) == 0)
            {
                converted = "0" + converted;
            }
            else
            {
                    
            }
        }
     }
 };
 
 class TestConvertToBinary
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
        int kthBit1 = 3;
        int kthBit2 = 6;
 
        int number1_bit_set = (solution.testKthBitSet(number1, kthBit1) == 0) ? 0 : 1;
        int number2_bit_set = (solution.testKthBitSet(number2, kthBit2) == 0) ? 0 : 1;

        System.out.println("The first number contains the value of " + number1 +".");
        System.out.println("Its bit " + kthBit1 + " has the value of " + number1_bit_set);
        System.out.println("The second number contains the value of " + number2 +".");
        System.out.println("Its bit " + kthBit2 + " has the value of " + number2_bit_set);

    }
 };
 
 
 