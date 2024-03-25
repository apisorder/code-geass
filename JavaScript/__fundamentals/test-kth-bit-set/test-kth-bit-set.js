
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:26AM 02-03-2024
//  *  Problem:                        Test If Kth Bit Is Set (Zero)
// @param {Integer} number
// @param {Integer} kthBit
// @return {Integer}
//

let testKthBitSet = (number, kthBit) =>
{

//********************************************************************************************************************
//  Step 1: LEFT-SHIFT 1 k bits and AND it with the number will test whether kth bit is set (1) or not (0)
//********************************************************************************************************************
    
    return (number & (1 << kthBit));
}

//  64  32  16  8   4   2   0
//  1   0   0   1   0   0   0
//  0   0   1   0   1   0   0

let number1 = 72;
let number2 = 20;
let kthBit1 = 3;
let kthBit2 = 6;

console.log("First number has value of " + number1 + ".");
console.log("Its bit " + kthBit1 + " has the value of " + (testKthBitSet(number1, kthBit1) ? 1: 0)); 
console.log("Second number has value of " + number2 + ".");
console.log("Its bit " + kthBit2 + " has the value of " + (testKthBitSet(number2, kthBit2) ? 1: 0)); 

