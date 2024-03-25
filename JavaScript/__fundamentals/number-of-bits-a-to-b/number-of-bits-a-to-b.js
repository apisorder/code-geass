
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  08:08AM 02-02-2024
//  *  Problem:                        Number Of Bits A To B (Zero)
// @param {Integer} number1
// @param {Integer} number2
// @return {Integer}
//

let numberOfBitsAToB = (number1, number2) =>
{

//********************************************************************************************************************
//  Step 1: XOR the two numbers to get a number of their differences 
//********************************************************************************************************************
        
    let result = number1 ^ number2;
    let numberOfBits = 0;

//********************************************************************************************************************
//  Step 2: calculate the number of bits where the two numbers are different
//********************************************************************************************************************
    
    while (result > 0) 
    {
        numberOfBits += (result & 1);
        result >>= 1;
    }
    return numberOfBits;
}

//  64  32  16  8   4   2   0
//  1   0   1   1   0   0   0
//  0   0   1   0   1   0   0

let number1 = 88;
let number2 = 20;
let kthBit = 4;

console.log("First number has value of " + number1 + ".");
console.log("Second number has value of " + number2 + ".");
console.log("The number of bits needed to convert the numbers = " + numberOfBitsAToB(number1, number2));
