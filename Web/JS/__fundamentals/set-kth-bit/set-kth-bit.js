
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  02:28PM 02-02-2024
//  *  Problem:                        Set Kth Bit (Zero)
// @param {Integer} number
// @param {Integer} kthBit
// @return {Integer}
//

let setKthBit = (number, kthBit) =>
{

//********************************************************************************************************************
//  Step 1: LEFT-SHIFT 1 k bits and OR it with the number will always turn kth bit on in the number
//********************************************************************************************************************
    
    return (number | (1 << kthBit));
}

//  64  32  16  8   4   2   0
//  1   0   0   1   0   0   0
//  0   0   1   0   1   0   0

number1 = 72
number2 = 20
kthBit = 1

console.log("First number has value of " + number1 + ".");
console.log("Second number has value of " + number2 + ".");
console.log("After setting bit " + kthBit + ".");
console.log("First number has value of " + setKthBit(number1, kthBit) + ".");
console.log("Second number has value of " + setKthBit(number2, kthBit) + ".");
