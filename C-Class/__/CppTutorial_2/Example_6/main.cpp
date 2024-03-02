
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:09PM 02-28-2024
 *  Problem:                        argc, and argv (Zero)
 * @param {}
 * @return {Integer}
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() 
{
    
    //  ----- PROBLEM CALCULATOR -----
    //  Enter calculation (ex. 5 + 6) : 10 - 6
    //  10.0 - 6.0 = 4.0
    double operand1 = 0;
    double operand2 = 0;
    std::cout << "Enter calculation (ex. 5 + 6) : 10 - 6" << std::endl;
    std::cout << "10.0 - 6.0 = 4.0" << std::endl;

    std::string userInput;
    getline(std::cin, userInput);

    std::stringstream sUserInput(userInput);
    std::vector<std::string> userInputVector;
    char stopper = ' ';

    while (getline(sUserInput, userInput, stopper))
    {
        userInputVector.push_back(userInput);
    }

    operand1 = std::stod(userInputVector[0]);
    operand2 = std::stod(userInputVector[2]);

    double result;
    std::string operation = userInputVector[1];

    if (operation == "+")
    {
        result = operand1 + operand2;
    }
    else if (operation == "-")
    {
    result = operand1 - operand2;
    }
    else if (operation == "*")
    {
        result = operand1 * operand2;
    }
    else if (operation == "/")
    {
        result = operand1 / operand2;
    }
    else
    {
        std::cout << "Please enter only +, -, *, /" << std::endl;
    }

    printf("%.1f %s %.1f = %.1f\n", operand1, operation.c_str(), operand2, result);
    
    // ----- END PROBLEM CALCULATOR -----
    return 0;
}