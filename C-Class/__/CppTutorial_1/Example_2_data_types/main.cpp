
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  06:00PM 02-27-2024
 *  Problem:                        type ranges, and precision limits (Zero)
 * @param {Integer} argc {String} argv
 * @return {Integer}
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
 
#include <limits>
// functions for min and max values for data types

int g_iRandomNum = 0;
//  global variable using Hungarian notation

const double PI = 3.14159;
//  constants

int main(int argc, char** argv)
{
    bool bMarried = true;
    
    char chMyGrade = 'A';
    //  char stores 256 single characters represented 
    //  by your keyboard
    
    unsigned short int u16Age = 43;
    //  unsigned (nonnegative only) short ints hold values from 0 to 65,535
    
    short int siWeight = 180;
    //  short ints store between -32,768 to 32,767
    
    int nDays = 7;
    //  ints range from -2147483648 to 2147483647
    
    long lBigNum = 1000000;
    //  long ints and long long ints range 
    //  from -9223372036854775808 to 9223372036854775807
    
    float fPi = 3.14159;
    //  floats range from 1.17549e-38 to 3.40282e+38

    float fBigFloat = 1.1111111111;
    float fBigFloat2 = 1.1111111111;
    float fFloatSum = fBigFloat + fBigFloat2;
    //  demonstrate how float (6) and double (15) have limited precision    

    printf("fFloatSum Precision : %.10f\n", fFloatSum);
    
    std::cout << "Min double " << 
            std::numeric_limits<double>::min() << "\n";
    std::cout << "Max double " << 
            std::numeric_limits<double>::max() << "\n";

    float BigFloat = 1.11111111111111111111;
    float BigFloat2 = 1.11111111111111111111;
    float FloatSum = BigFloat + BigFloat2;

    double dbBigFloat = 1.11111111111111111111;
    double dbBigFloat2 = 1.11111111111111111111;
    double dbFloatSum = dbBigFloat + dbBigFloat2;
    // doubles range from 2.22507e-308 to 1.79769e+308

    printf("FloatSum Precision : %.10f\n", FloatSum);

    printf("dbFloatSum Precision : %.20f\n", dbFloatSum);
    //  Double addition has 15 digits of precision
    
    long double ldPi = 3.1415926535897932;
    //  long doubles range from 3.3621e-4932 to 1.18973e+4932
    
    auto whatWillIBe = true;
    //  You can have the compiler assign a type
    
    //  SHOW DATA TYPES MIN & MAX VALUES
    std::cout << "Min bool " << 
        std::numeric_limits<bool>::min() << "\n";
    std::cout << "Max bool " << 
        std::numeric_limits<bool>::max() << "\n";
    
    std::cout << "Min unsigned short int " << 
            std::numeric_limits<unsigned short int>::min() << "\n";
    std::cout << "Max unsigned short int " << 
            std::numeric_limits<unsigned short int>::max() << "\n";
    
    std::cout << "Min short int " << 
            std::numeric_limits<short int>::min() << "\n";
    std::cout << "Max short int " << 
            std::numeric_limits<short int>::max() << "\n";

    std::cout << "Min int " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max int " << std::numeric_limits<int>::max() << "\n";

    std::cout << "Min long " << std::numeric_limits<long int>::min() << "\n";
    std::cout << "Max long " << std::numeric_limits<long int>::max() << "\n";

    std::cout << "Min float " << 
            std::numeric_limits<float>::min() << "\n";
    std::cout << "Max float " << 
            std::numeric_limits<float>::max() << "\n";
    
    std::cout << "Min long double " << 
            std::numeric_limits<long double>::min() << "\n";
    std::cout << "Max long double " << 
            std::numeric_limits<long double>::max() << "\n";
    
    std::cout << "int Size " << sizeof(int) << "\n";
    //  Get the number of bytes used by a type
    
    printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");
    //  char, int, 5 space right justified int, 
    //  3 decimal float / double, string specifiers
    
    return 0;
}