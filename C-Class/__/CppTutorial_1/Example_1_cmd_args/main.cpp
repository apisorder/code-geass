
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, char** argv)
{
    std::cout << "Hello World" << std::endl;

    //  check if any arguments are passed

    // If you compile the code into an executable program in the terminal
    // g++ main.cpp
    // And execute it : ./a.out I Love C++
    // You'd see how to work with passed arguments
    
    // If no arguments are passed argc has a value of 1
    // We check that with if to skip printing values if none were passed
    if (argc != 1)
    {

    // << : Stream insertion operator which puts the string
    // into the cout stream to display it
        std::cout << "You entered " << argc <<
            " arguments\n";
    }

    for ( int i = 0; i < argc; ++i )
    {
        std::cout << argv[i] << "\n";
    }

    // When 0 is returned that signals that the program executed without 
    // an error and -1 signals an error occurred 
    return 0;
}