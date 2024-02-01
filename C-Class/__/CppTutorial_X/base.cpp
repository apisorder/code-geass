









-------------------- Circle.h --------------------


-------------------- Circle.cpp --------------------


-------------------- MULTIPLE TOPICS --------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <fstream> // Used for file IO

using namespace std;

// ---------- STRUCTS ----------

// Classes have default private fields and methods
// while structs have public
// Structs are used to model new data types, while
// classes model more complex real world objects
struct Shape{
    // Variables are public by default
    double length, width;

    // Constructors are public by default
    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }

    // Structs can contain functions
    double Area(){
        return length * width;
    }

    // Structs can contain private members
private:
    int id;
};

// You can inherit from a struct
struct Circle : Shape{
    // Override the constructor
    // You also use this with structs
    Circle(double width){
        this->width = width;
    }

    // Override Area()
    double Area(){
        return 3.14159 * pow((width / 2), 2);
    }
};

// ---------- USED WITH LAMBDA EXPRESIONS ----------
vector<int> GenerateRandVec(int numOfNums,
        int min, int max);

// ---------- OPERATOR OVERLOADING ----------
// You can define custom operators just as you define functions
// This allows you to compare, perform calculations, etc.
// with your objects in custom ways

// Create a custom Box class with overloaded operators
class Box{
public:
    double length, width, breadth;

    // Used to hold a string representation of a box
    string boxString;

    Box(){
        length = 1, width = 1, breadth = 1;
    }
    Box(double l, double w, double b){
        length = l, width = w, breadth = b;
    }

    // You can define customer operators just like
    // you define functions
    // This is a unary operator because it operates
    // on 1 object
    // Other Unary Operators : --, *(pointer dereference),
    // -> (Member Selection), !, & (Address of), +, -
    Box& operator ++ (){
        length++;
        width++;
        breadth++;
        return *this;
    }

    // Creates a C string representation which is a
    // pointer to an array that is null terminated
    operator const char*() {
        // Creates a stream that can be loaded with
        // characters that can then be accessed as
        // a string object
        ostringstream boxStream;
        boxStream << "Box : " <<
                length << ", " <<
                width << ", " <<
                breadth;

        // Return a string representation of the stream
        boxString = boxStream.str();

        // Returns the pointer to the string array
        return boxString.c_str();
    }

    // Binary operators operate on 2 objects
    // +, -, *, /, %, ==, !=, >, <, >=, <=, &&, ||,
    // !, =, +=, -=, *=, /=, ^, [], &, |

    // Let's add boxes
    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;
        return boxSum;
    }

    // Check for box equality
    bool operator == (const Box& box2){
        return ((length == box2.length) &&
                (width == box2.width) &&
                (breadth == box2.breadth));
    }
};


int main()
{
    // Create a struct
    Shape shape(10, 10);

    // Call a Struct function
    cout << "Square Area : " << shape.Area()
            << endl;

    // Create a struct
    Circle circle(10);

    // Call a Struct function
    cout << "Circle Area : " << circle.Area()
            << endl;

    // You can initialize a struct or class using
    // an aggregate
    Shape rectangle{10,15};
    cout << "Rectangle Area : " <<
            rectangle.Area() << endl;

    // ---------- LAMBDA EXPRESSIONS ----------
    vector<int> vecVals = GenerateRandVec(10, 1, 50);

    // Lambda Expressions make it easy to perform list
    // operations in one line of code. You designate
    // them with []
    // Here we sort a vector
    sort(vecVals.begin(), vecVals.end(),
            [](int x, int y){ return x < y; });

    for(auto val: vecVals)
        cout << val << endl;

    cout << endl;

    // copy_if works like filter does in other languages
    // Here we keep only even values in a new vector
    vector<int> evenVecVals;

    copy_if(vecVals.begin(), vecVals.end(),
            back_inserter(evenVecVals),
            [](int x){ return (x % 2) == 0; });

    for(auto val: evenVecVals)
        cout << val << endl;

    // ----- SUM A LIST -----
    int sum = 0;

    // for_each cycles through all values
    // [&] captures all variables used
    // in the body of the lambda by reference
    for_each(vecVals.begin(), vecVals.end(),
            [&] (int x) {sum += x; });

            cout << "SUM : " << sum << endl;

    // ----- RECURSIVE LAMBDA FUNCTIONS -----

    // Recursive Lambda to calculate Fibonacci Numbers
    function<int(int)> Fib =
    [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};

    // Fib(0) = 0
    // Fib(1) = 1
    // Fib(2) = 1
    // Fib(3) = 2
    // Fib(4) = 3
    cout << "Fib 4 : " << Fib(4) << endl;

    // ---------- OPERATOR OVERLOADING ----------

    Box box(10,10,10);

    // Will increment all values in the box by 1
    ++box;
    cout << box << endl;

    // Add boxes
    Box box2(5,5,5);
    cout << "Box1 + Box2 = " <<
            box + box2 << endl;

    // Check equality
    cout << "Are boxes equal : " <<
            (box == box2) << endl;

    // ---------- FILE IO ----------
    ofstream writeToFile;
    ifstream readFromFile;
    string txtToWrite = "";
    string txtFromFile = "";

    // We open the file by providing a name and then either
    // ios::app : Append to the end of the file
    // ios::trunc : If the exists delete content
    // ios::in : Open file for reading
    // ios::out : Open file for writing
    // ios::ate : Open writing and move to the end of the file
    writeToFile.open("test.txt", ios_base::out |
            ios_base::trunc);

    if(writeToFile.is_open()){
        // You can write with the stream insertion operator
        writeToFile << "Beginning of File\n";

        // You can write data in a string
        cout << "Enter data to write : ";
        getline(cin, txtToWrite);
        writeToFile << txtToWrite;

        // Close the file
        writeToFile.close();
    }

    // Open the file for reading
    readFromFile.open("test.txt", ios_base::in);

    if(readFromFile.is_open()){

        // Read text from file
        while(readFromFile.good()){
            getline(readFromFile, txtFromFile);

            // Print text from file
            cout << txtFromFile << endl;
        }
        readFromFile.close();
    }

    return 0;
}

// ---------- USED WITH LAMBDA EXPRESIONS ----------

vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums){
        randVal = min + rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}

// ---------- FUNCTIONS AS OBJECTS ----------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <fstream> // Used for file IO

using namespace std;

// 1. Created to store as a variable and to
// pass into other functions
double MultBy2(double num){
    return num * 2;
}

// 2. Functions can receive other functions
// the first double is the return type followed
// by the data types for the parameter
double DoMath(function<double(double)> func, double num){
    return func(num);
}

// 3. You can store functions in a vector
double MultBy3(double num){
    return num * 3;
}


int main()
{
    // 1. You can store functions as variables
    auto times2 = MultBy2;
    cout << "5 * 2 = " <<
            times2(5) << endl;

    // 2. Pass a function into a function
    cout << "6 * 2 = " <<
            DoMath(times2, 6) << endl;

    // 3. You can store functions in a vector
    // Create a vector using the function parameters
    // and then load the functions into the vector
    vector<function<double(double)>> funcs (2);
    funcs[0] = MultBy2;
    funcs[1] = MultBy3;
    cout << "2 * 10 = " <<
            funcs[0](10) << endl;

    return 0;
}

-------------------- TEMPLATES / ITERATORS --------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <fstream> // Used for file IO
#include <deque>
#include <iterator>

using namespace std;

// ---------- MACROS ----------
// This is a macro constant that will replace
// PI with 3.14159 in the code before execution
#define PI 3.14159

// This is a macro function that will do the same with
// a function
#define AREA_CIRCLE(radius) (PI * (pow(radius, 2)))

// ----- TEMPLATE FUNCTIONS -----

// We use templates to create functions or classes
// that can work with many types
// Templates differ from function overloading in that
// instead of having a function that does similar
// things with different objects a template does the
// same thing with different objects

// This says this is a function template that generates
// functions that except 1 parameter
template <typename T>
void Times2(T val){
    cout << val << " * 2 = " <<
            val * 2 << endl;
}

// Receive multiple parameters and return a value
template <typename T>
T Add(T val, T val2){
    return val + val2;
}

// Work with chars and strings
template <typename T>
T Max(T val, T val2){
    return (val < val2) ? val2 : val;
}

// ----- TEMPLATE CLASSES -----

// Template classes are classes that can work with
// different data types

// You can define that you may receive parameters
// with different types, but they don't have to
// be different
template <typename T, typename U>
class Person{
public:
    T height;
    U weight;
    static int numOfPeople;
    Person(T h, U w){
        height = h, weight = w;
        numOfPeople++;
    }
    void GetData(){
        cout << "Height : " <<
            height <<
            " and Weight : " <<
            weight << endl;
    }
};

// You have to initialize static class members
template<typename T, typename U> int Person<T, U>::numOfPeople;

int main()
{
    cout << "Circle Area : " <<
            AREA_CIRCLE(5) << endl;

    // ----- TEMPLATE FUNCTIONS -----
    // The template function can receive ints or floats
    Times2(5);
    Times2(5.3);

    // Multiple parameters and returned value
    cout << "5 + 4 = " <<
            Add(5,4) << endl;
    cout << "5.5 + 4.6 = " <<
            Add(5.5,4.6) << endl;

    // Get biggest value
    cout << "Max 4 or 8 = " <<
            Max(4, 8) << endl;
    cout << "Max A or B = " <<
            Max('A', 'B') << endl;
    cout << "Max Dog or Cat = " <<
            Max("Dog", "Cat") << endl;

    // ----- END OF TEMPLATE FUNCTIONS -----

    // ----- TEMPLATE CLASSES -----

    // When creating the object you must define the
    // data types used
    Person<double, int> mikeTyson (5.83, 216);
    mikeTyson.GetData();

    // You access static values using the object
    // and not the class
    cout << "Number of people : " <<
            mikeTyson.numOfPeople << endl;

    // ----- END OF TEMPLATE CLASSES -----

    // ----- CONTAINERS -----
    // We have already seen the STL container vector
    // There are many other special ways of storing data

    // ----- DOUBLE ENDED QUEUE -----

    // A double ended queue (Deck) is a dynamic array that can
    // be expanded or contracted on both ends
    deque<int> nums = {1,2,3,4};
    nums.push_front(0);
    nums.push_back(5);
    for(int x: nums)
        cout << x << endl;

    // You can access index values, but they are costly
    // because values aren't stored contigously, but
    // instead use multiple arrays
    cout << nums[0] << endl;

    // ----- END DOUBLE ENDED QUEUE -----

    // ----- ITERATORS -----
    // Iterators are used to point at container
    // memory locations
    vector<int> nums2 = {1,2,3,4};

    // Define an iterator as the same type
    vector<int>::iterator itr;

    // Refer to the vectors begin and end while
    // incrementing the iterator
    for(itr = nums2.begin();
            itr < nums2.end();
            itr++){

        // Get value at the pointer
        cout << *itr << endl;
    }

    // You can also increment a set number of spaces
    // Create an iterator and point it at the beginning
    // of the vector
    vector<int>::iterator itr2 = nums2.begin();

    // Advance 2 spaces
    advance(itr2, 2);
    cout << *itr2 << endl;

    // Next works like advance, but it returns an
    // iterator
    auto itr3 = next(itr2, 1);
    cout << *itr3 << endl;

    // Previous moves a set number of indexes and
    // returns an iterator
    auto itr4 = prev(itr2, 1);
    cout << *itr4 << endl;

    // You can also insert at a defined index
    vector<int> nums3 = {1,4,5,6};
    vector<int> nums4 = {2,3};
    auto itr5 = nums3.begin();
    advance(itr5, 1);
    copy(nums4.begin(), nums4.end(),
            inserter(nums3, itr5));

    for(int &i: nums3)
        cout << i << endl;

    return 0; }
-------------------- POINTERS / MALLOC / TEMPLATES --------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <iterator>
#include <memory>
#include <stdio.h>

using namespace std;

// A Smart pointer is a class that provides the
// power of pointers, but also handles the reallocation
// of memory when it is no longer required (The pointer
// is automatically destroyed)

// typedef creates an alias for a more complex type name
typedef vector<int32_t> intVec;

int main()
{
    /* MALLOC EXAMPLE
    // When you define a primitive type like int or
    // float you define exactly the amount of space
    // to set aside

    // If you need to define how much space to set aside
    // you could call malloc() and tell it how much
    // space to set aside and it returns the address to
    // that memory address

    int amtToStore;
    cout << "How many numbers do you want to store : ";
    cin >> amtToStore;

    // Create an int pointer and set aside enough space
    int * pNums;

    // Cast the pointer and define how much space to set aside
    pNums = (int *) malloc(amtToStore * sizeof(int));

    // Check if memory was allocated
    if(pNums != NULL){
        int i = 0;

        // Store values
        while(i < amtToStore){
            cout << "Enter a Number : ";
            cin >> pNums[i];
            i++;
        }
    }

    cout << "You entered these numbers\n";
    for(int i = 0; i < amtToStore; i++){
        cout << pNums[i] << endl;
    }

    // Delete the pointer
    delete pNums;
    */

    // Smart Pointer Solution
    int amtToStore;
    cout << "How many numbers do you want to store : ";
    cin >> amtToStore;

    // This memory will be automatically reallocated
    unique_ptr<int[]> pNums(new int[amtToStore]);

    // unique_ptr can only have one owner
    // so this throws an error
    // unique_ptr<int[]> pNums2 = pNums;
    // I'll cover how to do this with shared_ptr
    // in a later tutorial

    if(pNums != NULL){
        int i = 0;

        // Store values
        while(i < amtToStore){
            cout << "Enter a Number : ";
            cin >> pNums[i];
            i++;
        }
    }

    cout << "You entered these numbers\n";
    for(int i = 0; i < amtToStore; i++){
        cout << pNums[i] << endl;
    }

    return 0;
}

// Here I demonstrate how to use templates
// polymorphically

// Base class all pizzas inherit along with MakePizza
// which will be overridden
class Pizza{
public:
    virtual void MakePizza() = 0;
};

// The last templates that will be called
class NYStyleCrust {
public:
  string AddIngredient() {
    return "Crust so Thin You can See through it\n\n";
  }
};

class DeepDishCrust {
public:
  string AddIngredient() {
    return "Super Awesome Chicago Deep Dish Crust\n\n";
  }
};

// End of last templates called

// The middle templates called
template <typename T>
class LotsOfMeat: public T {
public:
  string AddIngredient() {
    return "Lots of Random Meat, " + T::AddIngredient();
  }
};

template <typename T>
class Vegan: public T {
public:
  string AddIngredient() {
    return "Vegan Cheese, Veggies, " + T::AddIngredient();
  }
};

// End of middle templates called

// We inherit from Pizza as well as the initial next template
template <typename T>
class MeatNYStyle: public T, public Pizza {
public:
  void MakePizza() { cout << "Meat NY Style Pizza : " <<
          T::AddIngredient(); }
};

template <typename T>
class VeganDeepDish: public T, public Pizza {
public:
  void MakePizza() { cout << "Vegan Deep Dish : " <<
          T::AddIngredient(); }
};

int main()
{
    // unique_ptr is a smart pointer that disposes of
    // a pointer when it is no longer in use
    vector<unique_ptr<Pizza>> pizzaOrders;

    // Generate Pizza types and place them at the end of the vector
    pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
    pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

    // Call the pizzas and execute the directions
    // for making them
    for(auto &pizza: pizzaOrders){
        pizza->MakePizza();
    }

    return 0;
}

// ---------- THREADS ----------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

using namespace std;

int GetRandom(int max){
    srand(time(NULL));
    return rand() % max;
}

// ----- SIMPLE THREAD EXAMPLE -----

void ExecuteThread(int id){
    // Get current time
    auto nowTime = chrono::system_clock::now(); 

    // Convert to a time we can output
    time_t sleepTime =
            chrono::system_clock::to_time_t(nowTime);

    // Convert to current time zone
    tm myLocalTime = *localtime(&sleepTime);

    // Print full time information
    cout << "Thread " << id <<
            " Sleep Time : " <<
            ctime(&sleepTime) << endl;

    // Get separate pieces
    cout << "Month : " <<
            myLocalTime.tm_mon << endl;
    cout << "Day : " <<
            myLocalTime.tm_mday << endl;
    cout << "Year : " <<
            myLocalTime.tm_year + 1900 << endl;
    cout << "Hours : " <<
            myLocalTime.tm_hour << endl;
    cout << "Minutes : " <<
            myLocalTime.tm_min << endl;
    cout << "Seconds : " <<
            myLocalTime.tm_sec << "\n" << endl;

    // Put the thread to sleep for up to 3 seconds
    this_thread::sleep_for (chrono::seconds(GetRandom(3)));
    nowTime = chrono::system_clock::now();
    sleepTime =
            chrono::system_clock::to_time_t(nowTime);
    cout << "Thread " << id <<
            " Awake Time : " <<
            ctime(&sleepTime) << endl;

}

int main()
{
  // Create a thread and pass a parameter
  // to the function
  thread th1 (ExecuteThread, 1);

  // Join the thread to the main thread
  // meaning main waits for this thread to
  // stop executing before continuing execution
  // of code in main
  th1.join();

  thread th2 (ExecuteThread, 2);
  th2.join();

  return 0;
}


// ---------- SEQUENCE CONTAINERS ----------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
#include <deque>
#include <list>
#include<forward_list>

bool isEven(const int& val){
    return (val % 2) == 0;
}

int main()
{

    // Contains data stored in order

    // ---------- DEQUES ----------

    // A deque (Deck) is a dynamic array like vectors
    // except it also allows for insertion or deletion
    // from the front
    deque<int> deq1;

    // Add to the end and front
    deq1.push_back(5);
    deq1.push_front(1);

    // Add values with assign
    deq1.assign({11,12});

    // Get the size
    cout << "Size : " << deq1.size()
            << endl;

    // Access by index
    cout << deq1[0] << endl;
    cout << deq1.at(1) << endl;

    // Add at an index using an iterator
    deque<int>::iterator it = deq1.begin() + 1;
    deq1.insert(it, 3);

    // Add multiple values
    int tempArr[5] = {6,7,8,9,10};
    deq1.insert(deq1.end(), tempArr, tempArr+5);

    // Erase at an index
    deq1.erase(deq1.end());

    // Erase 1st 2 elements
    deq1.erase(deq1.begin(), deq1.begin()+2);

    // Pop first value
    deq1.pop_front();

    // Pop last
    deq1.pop_back();

    // Create a deque with 2 50s
    deque<int> deq2(2,50);

    // Swap values in deques
    deq1.swap(deq2);

    // Delete all values
    deq1.clear();

    // Cycle through the deque
    for(int i : deq1)
        cout << i << endl;

    // ---------- END DEQUES ----------

    // ---------- LIST ----------
    // Lists are the most efficient at inserting,
    // moving and extracting elements, but lack
    // direct access to elements

    // Add values
    int arr[5] = {1,2,3,4,5};
    list<int> list1;
    list1.insert(list1.begin(), arr, arr+5);

    // Adding values with assign
    list1.assign({10,20,30});

    // Add to end and front
    list1.push_back(5);
    list1.push_front(1);

    // Get the size
    cout << "Size : " << list1.size()
            << endl;

    // Can't access index
    // cout << list1[0] << endl;

    // You can access the index with an iterator
    list<int>::iterator it2 = list1.begin();
    advance(it2, 1);
    cout << "2nd Index : " <<
            *it2 << endl;

    // Insert at an index
    it2 = list1.begin();
    list1.insert(it2, 8);

    // Erase at an index
    list1.erase(list1.begin());

    // Erase 1st 2 elements
    it2 = list1.begin();
    list<int>::iterator it3 = list1.begin();
    advance(it3, 2);
    list1.erase(it2, it3);

    // Pop first value
    list1.pop_front();

    // Pop last
    list1.pop_back();

    // Create another list
    int arr2[6] = {10,9,8,7,6,6};
    list<int> list2;
    list2.insert(list2.begin(), arr2, arr2+5);

    // Sort the list
    list2.sort();

    // Reverse the list
    list2.reverse();

    // Remove duplicates
    list2.unique();

    // Remove a value
    list2.remove(6);

    // Remove if a condition is true
    list2.remove_if (isEven);

    // Merge lists
    list1.merge(list2);

    for(int i : list2)
        cout << i << endl;

    cout << endl;

    // Cycle through the list
    for(int i : list1)
        cout << i << endl;

    cout << endl;

    // ---------- END LIST ----------

    // ---------- FORWARD_LIST ----------
    // A forward list is like a list, but each list
    // item only has a link to the next item in the
    // list and not to the item that proceeds it.

    // This make them the quickest of the sequence
    // containers

    forward_list<int> fl1;

    // Assign values
    fl1.assign({1,2,3,4});

    // Push and pop front
    fl1.push_front(0);
    fl1.pop_front();

    // Get 1st
    cout << "Front : " << fl1.front();

    // Get iterator for 1st element
    forward_list<int>::iterator it4 = fl1.begin();

    // Insert after 1st element
    it4 = fl1.insert_after(it4, 5);

    // Delete just entered 5
    it4 = fl1.erase_after(fl1.begin());

    // Place in 1st position
    fl1.emplace_front(6);

    // Remove a value
    fl1.remove(6);

    // Remove if a condition is true
    fl1.remove_if (isEven);

    forward_list<int> fl2;
    fl2.assign({9,8,7,6,6});

    // Remove duplicates
    fl2.unique();

    // Sort
    fl2.sort();

    // Reverse
    fl2.reverse();

    // Merge lists
    fl1.merge(fl2);

    // Clear
    fl1.clear();

    for(int i : fl1)
        cout << i << endl;

    cout << endl;

    for(int i : fl2)
        cout << i << endl;

    // ---------- END FORWARD_LIST ----------

    return 0;
}



-------------------- MORE CONTAINERS --------------------

// ----- ASSOCIATIVE CONTAINERS -----
// Associative containers store sorted data
// which makes insertion slower, but searching
// faster

int main()
{
    // ----- SET -----
    // Sets store unique sorted values using a key
    set<int> set1 {5,4,3,2,1,1};
    cout << "Size : " << set1.size() <<
            endl;

    // Insert value
    set1.insert(0);

    // Subscript operator doesn't work
    // cout << set1[0] << endl;

    // Get values with an iterator
    set<int>::iterator it = set1.begin();
    it++;

    cout << "2nd : " << *it << endl;

    // Erase value
    set1.erase(5);

    // Erase last 2
    it = set1.end();
    advance(it, -2);
    set1.erase(it, set1.end());

    // Add multiple values
    int arr[] = {6,7,8,9};
    set1.insert(arr,arr+4);

    // Find value, get iterator and then value
    auto val = set1.find(6);
    cout << "Found : " << *val << endl;

    // Get iterator to value
    auto eight = set1.lower_bound(8);
    cout << "8 : " << *eight << endl;

    // Get iterator to value after
    auto nine = set1.upper_bound(8);
    cout << "9 : " << *nine << endl;

    // Swap values in sets
    set<int> set2 {10,11};
    set1.swap(set2);

    // Check if empty and if not print values
    if(!set1.empty()){
        for(int i : set1)
        cout << i << endl;
    }

    // ----- END OF SET -----

    cout << endl;

    // ----- MULTISET -----
    // Stores duplicate values in sorted order
    // Other than that it is the same as set
    multiset<int> mset1 {1,1,2,3,4};

    // Insert value
    mset1.insert(4);
    mset1.insert(0);

    if(!mset1.empty()){
        for(int i : mset1)
        cout << i << endl;
    }

    // ----- END MULTISET -----

    cout << endl;

    // ----- MAP -----
    // Stores using key value pairs and you
    // can't have duplicate keys
    map<int, string> map1;

    // Insert key values
    map1.insert(pair <int, string> (1, "Bart"));
    map1.insert(pair <int, string> (2, "Lisa"));
    map1.insert(pair <int, string> (3, "Marge"));
    map1.insert(pair <int, string> (4, "Homer"));

    // Find element by key
    auto match = map1.find(1);
    cout << match->second << endl;

    // Get iterator to value
    auto bart = map1.lower_bound(1);
    cout << "LB : " << bart->second << endl;

    // Get next iterator
    auto lisa = map1.upper_bound(1);
    cout << "UB : " << lisa->second << endl;

    // Print elements with an iterator
    map<int, string>::iterator it2;
    for(it2 = map1.begin(); it2 != map1.end(); ++it2){
        cout << "Key : " << it2->first << endl;
        cout << "Value : " << it2->second << endl;
    }

    // ----- END OF MAP -----

    // ----- MULTIMAP -----
    // Like map except you can have duplicate keys as long
    // as the values are different
    multimap<int, string> mmap1;
    mmap1.insert(pair <int, string> (1, "Bart"));
    mmap1.insert(pair <int, string> (1, "Lisa"));
    mmap1.insert(pair <int, string> (3, "Marge"));
    map<int, string>::iterator it3;
    for(it3 = mmap1.begin(); it3 != mmap1.end(); ++it3){
        cout << "Key : " << it3->first << endl;
        cout << "Value : " << it3->second << endl;
    }

    // ----- END OF MULTIMAP -----

    // ----- CONTAINER ADAPTERS -----
    // Adapt containers to provide a defined interface

    // ----- STACK -----
    // Provides an interface for storing elements in a LIFO
    // format
    stack<string> custs;
    custs.push("George");
    custs.push("Louise");
    custs.push("Florence");

    // Get number of elements
    int size = custs.size();

    // Check if empty
    if(!custs.empty()){
        for(int i = 0; i < size; i++){

            // Get value with top
            cout << custs.top() << endl;

            // Delete last value entered
            custs.pop();
        }
    }

    // ----- END OF STACK -----

    // ----- QUEUE -----
    // Provides an interface for storing elements in a FIFO
    // format
    queue<string> cast;
    cast.push("Zoidberg");
    cast.push("Bender");
    cast.push("Leela");
    int size2 = cast.size();

    if(!cast.empty()){
        for(int i = 0; i < size2; i++){

            // Get value with top
            cout << cast.front() << endl;

            // Delete last value entered
            cast.pop();
        }
    }

    // ----- END OF QUEUE -----

    // ----- PRIORITY QUEUE -----
    // Elements are organized with the largest first
    priority_queue<int> nums;
    nums.push(4);
    nums.push(8);
    nums.push(5);
    int size3 = nums.size();

    if(!nums.empty()){
        for(int i = 0; i < size3; i++){

            // Get value with top
            cout << nums.top() << endl;

            // Delete last value entered
            nums.pop();
        }
    }

    // ----- END OF PRIORITY QUEUE -----

    // ----- ENUMS -----
    // Custom data type that assigns names to
    // constant integers so that a program is
    // easier to read

    // You can define the starting index, or any others
    enum day{Mon=1, Tues, Wed, Thur, Fri=5};

    enum day tuesday = Tues;

    cout << "Tuesday is the " << tuesday <<
            "nd day of the week\n";

    // Cycle through days
    for(int i = Mon; i <= Fri; i++)
        cout << i << endl;

    // ----- END OF ENUMS -----

    return 0;
}


-------------------- REGULAR EXPRESSIONS --------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>

#include <regex>

using namespace std;

int main(int argc, char** argv) {
    
    // The string to search
    string str = "The ape was at the apex";
    
    // We want to match for ape with or 
    // without a space after it
    regex reg ("(ape)[^ ]?");
    
    // Provides useful function when you
    // are searching a string
    smatch matches;
    
    // If there is a match for the regex
    if(regex_search(str, matches, reg) == true){
        
        // Output the number of matches
        cout << matches.size() << " Matches" << endl;
        
        // Cycle through the matches
        while(regex_search(str, matches, reg)){
        
            // Get the match
            cout << matches.str(1) << endl;
            // Get the index
            cout << "At Index " << matches.position(1) << endl;
        
            // Eliminate the previous match and create
            // a new string to search
            str = matches.suffix().str();
        }
    }
    return 0;
}