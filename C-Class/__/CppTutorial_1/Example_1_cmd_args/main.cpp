
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  07:40AM 02-27-2024
 *  Problem:                        argc, and argv (Zero)
 * @param {Integer} argc, {String} argv
 * @return {Integer}
 */

//  preprocessor directives

#include <cstdlib>
//  converting data types, random number generators, memory managment, searching, sorting, etc.

#include <iostream>
//  input and output operations

#include <string>
//  handle strings

#include <vector>
//  handle resizeable arrays

#include <sstream>
//  manipulate streams, or a series of characters

int main(int argc, char** argv)
{
    std::cout << "Hello World" << std::endl;

    //  to compile & specify output file
    //  g++ main.cpp -o main.exe
    //  to execute
    //  main.exe I Love C++

    //  check if any arguments are passed
    if (argc != 1)
    {
        std::cout << "You entered " << argc <<
            " arguments\n";
    }

    //  cycle through the array of arguments
    for ( int i = 0; i < argc; ++i )
    {
        std::cout << argv[i] << "\n";
    }

    //  0 signfies successful program execution
    return 0;
}