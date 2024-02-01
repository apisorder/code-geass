
// The header file adds declarations for your
// code file

#ifndef SHAPE_H
#define SHAPE_H

// We will model a generic Shape in this class

// Protected fields & methods can only be accessed
// in this class, or in classes that inherit from
// the Shape class
// Private is used when you want to block access
// to all code aside from code in this class
// Public is used when you want to provide access
// to anything with access to an object
class Shape{
protected:
    double height;
    double width;

public:
    // Static variables share the same value for all
    // shape objects
    static int numOfShapes;

    // This is the constructor and it is called
    // every time a shape object is created
    // You can have multiple constructors with the same
    // name that differ only in the number of parameters
    // they accept
    // If only 1 parameter is passed will assume that
    // height and width are equal
    Shape(double length);
    Shape(double height, double width);
    Shape();

    // A deconstructor is called automatically when an object
    // is deleted or is no longer used
    // The default is fine, but you should create custom ones
    // when you must release memory, or resources
    virtual ~Shape();
    void SetHeight(double height);
    double GetHeight();
    void SetWidth(double width);
    double GetWidth();
    // Static methods can only access static fields
    static int GetNumOfShapes();
    virtual double Area();
};

#endif /* SHAPE_H */

-------------------- Shape.cpp --------------------

// Refer to the declarations in the header
#include "Shape.h"

// This file is called the implementation file

Shape::Shape(double length){
    this->height = length;
    this->width = length;
    // Refer to class fields and methods with ::
    Shape::numOfShapes++;
}
Shape::Shape(double height, double width){
    this->height = height;
    this->width = width;
    Shape::numOfShapes++;
}

Shape::~Shape() = default;

// We can protect access to our fields using getters
// and setters. We could block certain values
// from being assigned, or we could provide
// custom output like adding inches or centimeter
// to the height, or width

// Because we create the class before naming an
// object we don't know its name. We can use this
// to refer to objects.

// The pointer operator is used to access an
// objects fields and methods
void Shape::SetHeight(double height){this->height = height;}
double Shape::GetHeight(){return height;}
void Shape::SetWidth(double width){this->width = width;}
double Shape::GetWidth(){return width;}

int Shape::GetNumOfShapes(){return numOfShapes;}

// A method marked as virtual can be used
// polymorphically.
// Polymorphism is a feature in which similar
// objects can be treated the same, but also
// utilize their differences automatically
// for any methods marked as virtual
double Shape::Area(){
    return height * width;
}

int Shape::numOfShapes = 0;


/*
 Because Shape has no purpose aside from grouping similar
 objects it should really be an Abstract class.

class Shape{
public:
    virtual double Area() = 0;
};

class Circle : public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }

    // Override Area()
    // You should use override to force the
    // compiler to check if the base class
    // virtual fucntion is the same as
    // the subclass
    double Area() override{
        return 3.14159 * pow((width / 2), 2);
    }
};

// This function receives Shapes but uses the
// correct Area() automatically
void ShowArea(Shape& shape){
    cout << "Area : " << shape.Area() << endl;
}

int main()
{
    Rectangle rectangle(10,5);
    Circle circle(10);
    ShowArea(rectangle);
    ShowArea(circle);

    Square square(10,10);
    ShowArea(square);

    return 0;
}
 *
 */
