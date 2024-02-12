
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  01:22PM 02-02-2024
//  *  Problem:                        Determine Number Is Even Or Odd (Zero)
// @param {Integer} number
// @return {Integer}
//

let numberEvenOrOdd = ( number ) =>
{

//********************************************************************************************************************
//  Step 1: since all even numbers have only 1 set bit, and it's never at bit 0, AND the number with 1 = 0 
//********************************************************************************************************************
    
    if ((number & 1) == 0)
    {
        return "even"
    }
    else
    {
        return "odd"
    }
} 

let x = 11;
let y = 22;
console.log("First number has value of " + x + " and is "  + numberEvenOrOdd(x));
console.log("Second number has value of " + y + " and is " + numberEvenOrOdd(y));
