
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:27PM 1-31-2024
//  *  Problem:                        Clear Kth Bit (Zero)
//

let clearKthBit = (number, kthBit) =>
{
    return (number & (~(1 << kthBit)));
}

//  64  32  16  8   4   2   0
//  1   0   1   1   0   0   0
//  0   0   1   0   1   0   0

number1 = 88
number2 = 20
kthBit = 4

console.log("First number has value of " + number1 + ".");
console.log("Second number has value of " + number2 + ".");
console.log("After clearing bit " + kthBit + ".");
console.log("First number has value of " + clearKthBit(number1, kthBit) + ".");
console.log("Second number has value of " + clearKthBit(number2, kthBit) + ".");
