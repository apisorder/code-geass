
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:52PM 02-08-2024
 *  Problem:                        Convert to Binary (Zero)
 *  @param {Integer} num
 *  @return {String}
 */

 class Solution
 {
     public String ConvertToBinary(int num)
     {

//********************************************************************************************************************
//  Step 1: create an empty string
//********************************************************************************************************************

        String converted = new String();

//********************************************************************************************************************
//  Step 2: while the number isn't 0
//********************************************************************************************************************

        while (num != 0)
        {

//********************************************************************************************************************
//  Step 3: pre-pend a "0" or "1" based on whether the number is even or odd to the result
//********************************************************************************************************************

            if ((num & 1) == 0)
            {
                converted = "0" + converted;
            }
            else
            {
                converted = "1" + converted;
            }
            num >>= 1;
        }

//********************************************************************************************************************
//  Step 4: return the result
//********************************************************************************************************************

        return converted;
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

        System.out.println(solution.ConvertToBinary(number1));
        System.out.println(solution.ConvertToBinary(number2));
    }
 };
 
 
 