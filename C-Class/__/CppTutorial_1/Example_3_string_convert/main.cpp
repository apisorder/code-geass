
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:29AM 02-27-2024
 *  Problem:                        getline, stoi, stod (Zero)
 *  @param {None}
 *  @return {Integer}
 */

#include <cstdlib>
//  This header defines several general purpose functions, including dynamic memory management, 
//  random number generation, communication with the environment, integer arithmetics, searching, 
//  sorting and converting.
//  https://cplusplus.com/reference/cstdlib/

#include <iostream>
//  Standard Input / Output Streams Library

#include <string>

int main() 
{     
    //  same as std::string sQuestion = "Enter Number 1 :: ";
    std::string sQuestion1 ("Enter Number 1 : ");
    //  Create a string

    std::string sNum1;
    std::string sNum2;
    //  Create empty strings to store values
    
    std::cout << sQuestion1;
    getline(std::cin, sNum1);
    //  Receive user input and store it
    //  std::cin = user inut
    //  sNum1 = where to store it
    
    std::string sQuestion2 = "Enter Number 2 : ";

    std::cout << sQuestion2;
    getline(std::cin, sNum2);
    
    int nNum1 = std::stoi(sNum1);
    int nNum2 = std::stoi(sNum2);
    //  Convert from strings to int
    
    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));
    
    //  ----- PROBLEM : MILES TO KILOMETERS -----
    //  Sample knowing that kilometers = miles * 1.60934
    //  Enter Miles : 5
    //  5 miles equals 8.0467 kilometers

    std::string sNumOfMilesString;
    double dNumOfMiles;
    double dNumofKilometers;
    
    std::cout << "Enter the number of miles to convert : ";
    getline(std::cin, sNumOfMilesString);

    dNumOfMiles = std::stod(sNumOfMilesString);
    //  Convert from string to double

    dNumofKilometers = dNumOfMiles * 1.60934;
    //  Convert from miles to km
    
    printf("%.1f miles equals %.4f kilometers\n", dNumOfMiles, dNumofKilometers);
   //   Output the results
 
    return 0;
}