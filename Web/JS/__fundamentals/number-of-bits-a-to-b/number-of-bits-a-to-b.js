
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  11:31PM 1-31-2024
//  *  Problem:                        Number Of Bits A To B (Zero)
//

let numberOfBitsAToB = (number1, number2) =>
{
    let result = number1 ^ number2;
    let numberOfBits = 0;

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

number1 = 88
number2 = 20
kthBit = 4

console.log("First number has value of " + number1 + ".");
console.log("Second number has value of " + number2 + ".");
console.log("The number of bits needed to convert the numbers = " + numberOfBitsAToB(number1, number2));
