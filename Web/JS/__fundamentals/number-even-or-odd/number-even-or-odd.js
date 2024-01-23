
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  8:21PM 1-22-2024
//  *  Problem:                        Determine Number Is Even Or Odd (Zero)
//

let numberEvenOrOdd = ( number ) =>
{
    if ((number & 1) == 0)
    {
        return "even"
    }
    else
    {
        return "odd"
    }
} 

x = 11
y = 22
console.log("First number has value of " + x + " and is "  + numberEvenOrOdd(x));
console.log("Second number has value of " + y + " and is " + numberEvenOrOdd(y));
