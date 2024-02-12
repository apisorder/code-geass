
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  05:36PM 02-11-2024
//  *  Problem:                        Number of Bits Which Are One (Zero)
//  @param {integer} number
//  @return {integer}
//

let numberBitOnes = (number) =>
{

    let sum = 0;

    while (number > 0)
    {

//********************************************************************************************************************
//  Step 1: while number is not 0, count the number of 1's
//********************************************************************************************************************

        number = number & (number-1);
        sum += 1;
    }
    return sum;
}

//  64  32  16  8   4   2   0
//  1   0   1   1   0   0   0
//  0   0   1   0   1   0   0

let number1 = 88;
let number2 = 20;

console.log(number1 + " has " + numberBitOnes(number1) + " bit(s), which are one.");
console.log(number2 + " has " + numberBitOnes(number2) + " bit(s), which are one.");