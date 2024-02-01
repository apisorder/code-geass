
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:25PM 1-31-2024
//  *  Problem:                        Set Kth Bit (Zero)
//

let setKthBit = (number, kthBit) =>
{
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
