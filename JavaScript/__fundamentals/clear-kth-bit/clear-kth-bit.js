
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  09:21PM 02-01-2024
//  *  Problem:                        Clear Kth Bit (Zero)
//  @param {integer} number
//  @param {integer} kth bit
//  @return {integer}
//

let clearKthBit = (number, kthBit) =>
{

//********************************************************************************************************************
//  Step 1: AND the number with 0 LEFT-SHIFTED k bits (shift 1 then negate that) 
//********************************************************************************************************************

    return (number & (~(1 << kthBit)));
}

//  64  32  16  8   4   2   0
//  1   0   1   1   0   0   0
//  0   0   1   0   1   0   0

let number1 = 88;
let number2 = 20;
let kthBit = 4;

console.log("First number has value of " + number1 + ".");
console.log("Second number has value of " + number2 + ".");
console.log("After clearing bit " + kthBit + ".");
console.log("First number has value of " + clearKthBit(number1, kthBit) + ".");
console.log("Second number has value of " + clearKthBit(number2, kthBit) + ".");
