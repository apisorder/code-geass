
//
//  *  Programmer:                     Jeff C. Cheng
//  *  Last modified:                  8:22PM 1-22-2024
//  *  Problem:                        Swap Two Numbers (Zero)
//  *  Reference:                      https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment

let swapTwoNumbers = (a, b) =>
{
    [a, b] = [b, a]
    return [a, b]
}

x = 11
y = 22

console.log("Values before the function call")
console.log("x =", x)
console.log("y =", y)

result = swapTwoNumbers(x, y)

console.log("Values after the function call")
x = result[0]
y = result[1]
delete result
console.log("x =", x)
console.log("y =", y)
