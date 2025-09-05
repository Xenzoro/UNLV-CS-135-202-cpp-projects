#include <iostream>
using namespace std;

// Base class
class Rectangle {
public:
    void setWidth(int w);
    void setLength(int l);
    int getArea();
    Rectangle(int l, int w);
    Rectangle();
protected:
    int width;
    int length;
};

// Derived class
class derivedShape: public Rectangle {
public:
    void setWidth2(int ww);
    void setLength2(int ll);
    int getArea();
    derivedShape(int l1, int w1, int l2, int w2); // Constructor with parameters
    derivedShape(); //Default constructor
private:
    int length2;
    int width2;
};


void Rectangle::setWidth(int w){
    this->width;
}
void Rectangle::setLength(int l) {
    this->length;
}
int Rectangle::getArea() {
    return this->length * this->width;
}

void derivedShape::setWidth2(int w) {
    Rectangle::setWidth(w);
}
void derivedShape::setLength2(int ll) {
    Rectangle::setLength(ll);
}
int derivedShape::getArea() {

    return this->length * this->width * this->length2 * this->width2;
}