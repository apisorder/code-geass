
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:58PM 02-27-2024
 *  Problem:                        array, vector, stringstream, getline(stringstream, string, char) (Zero)
 * @param {Integer} argc, {String} argv
 * @return {Integer}
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() 
{     
    int arrnNums[10] = {1};
    //  Declare an array of ints with the value of 1
    //  Once the size is defined it can't change
    
    int arrnNums2[] = {1,2,3};
    //  Leave out the array length
    
    int arrnNums3[5] = {8, 9};
    //  Create an array and assign some values
    
    std::cout << "1st Value : " << arrnNums3[0] << "\n";
    //  Access array values using indexes starting with 0
    
    arrnNums3[0] = 7;
    //  Change a value

    std::cout << "1st Value : " << arrnNums3[0] << "\n";
    
    std::cout << "Array size : " << 
            sizeof(arrnNums3) / sizeof(*arrnNums3) << "\n";
    //  Get array size by getting the number of bytes
    //  set aside for the array and then 
    //  divide by the size of the 1st element
    
    int arrnNums4[2][2][2] = {{{1,2}, {3,4}},
    {{5,6}, {7,8}}};
    //  A multidimensional array is like a spreadsheet
    //  If you think of each as layers that contain columns
    //  1st Number : Which layer
    //  2nd Number : Which column
    //  3rd Number : Which row

    std::cout << arrnNums4[1][1][1] << "\n";
    //  Use vectors when you don't know how big your arrays may be
    
    std::vector<int> vecnRandNums (2);
    //  Create a vector with 2 spaces to start
    
    vecnRandNums[0] = 10;
    vecnRandNums[1] = 20;
    //  Add values 
    
    vecnRandNums.push_back(30);
    //  Add another value to the vector
    
    std::cout << "Vector Size : " << vecnRandNums.size() << "\n";
    //  Get size of vector
    
    std::cout << "Last Index : " << 
            vecnRandNums[vecnRandNums.size() - 1] << "\n";
    //  Get last value
    
    //  Convert a string into an array
    std::string sSentence = "This is a random string";
        
    //  Task - convert string to a vector
    std::stringstream ss(sSentence);
    //  A stringstream object receives strings separated
    //  by a space and then spits them out 1 by 1
    
    std::string sIndivString;
    //  Will temporarily hold each word in the string
    
    // Defines what separates the words
    char separator = ' ';
    
    std::vector<std::string> vecsWords;
    //  Create a vector of strings
    //  no need to specify size or initial values

    // While there are more words to extract keep executing
    // getline takes strings from a stream of words stored
    // in the stream and each time it finds a blanks space
    // it stores the word proceeding the space in sIndivStr
    while(getline(ss, sIndivString, separator)){
        
        // Put the string into a vector
        vecsWords.push_back(sIndivString);
    }
    
    for(int i = 0; i < vecsWords.size(); ++i)
    {
        std::cout << vecsWords[i] << "\n";
    }
    //  Cycle through each index in the vector and print
    //  out each word 
    
    return 0;
}
