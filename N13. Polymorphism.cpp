#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Polygon {
public:
    Polygon(double width, double height) : _width(width), _height(height) {}

    virtual ~Polygon() {}

    virtual double area() = 0;

    void nonVirtualFunc() { cout << "Calling Polygon::nonVirtualFunc" << endl; }

protected:
    double _width, _height;
};

class Rectangle : public Polygon {
public:
    Rectangle(double width, double height, bool is_square) : Polygon(width, height), _is_square(is_square) {}

    virtual double area() override { return _width * _height; }

    void nonVirtualFunc() { cout << "Calling Rectangle::nonVirtualFunc" << endl; }

private:
    bool _is_square;
};

class Triangle : public Polygon {
public:
    Triangle(double width, double height, bool is_equilateral)
        : Polygon(width, height), _is_equilateral(is_equilateral) {}

    virtual double area() override { return _width * _height / 2.; }

    void nonVirtualFunc() { cout << "Calling Triangle::nonVirtualFunc" << endl; }

private:
    bool _is_equilateral;
};

shared_ptr<Polygon> makePolySmartPtr(double width, double height, bool boolVal, string type) {
    if (type == "rectangle") {
        return make_shared<Rectangle>(width, height, boolVal);
    } else if (type == "triangle") {
        return make_shared<Triangle>(width, height, boolVal);
    }

    return nullptr;
}

Polygon* makePolyRegularPtr(double width, double height, bool boolVal, string type) {
    if (type == "rectangle") {
        return new Rectangle(width, height, boolVal);
    } else if (type == "triangle") {
        return new Triangle(width, height, boolVal);
    }

    return nullptr;
}

int main() {
    shared_ptr<Polygon> pRectangleSmart = makePolySmartPtr(5, 5, true, "rectangle");
    shared_ptr<Polygon> pTriangleSmart = makePolySmartPtr(5, 5, false, "triangle");
    cout << (*pRectangleSmart).area() << endl;
    cout << (*pTriangleSmart).area() << endl;
    (*pRectangleSmart).nonVirtualFunc();
    (*pTriangleSmart).nonVirtualFunc();

    Polygon* pRectangleRegular = makePolyRegularPtr(5, 5, true, "rectangle");
    Polygon* pTriangleRegular = makePolyRegularPtr(5, 5, true, "triangle");
    cout << (*pRectangleRegular).area() << endl;
    cout << (*pTriangleRegular).area() << endl;
    (*pRectangleRegular).nonVirtualFunc();
    (*pTriangleRegular).nonVirtualFunc();

    Rectangle rect(5, 5, true);
    Triangle trgl(5, 5, false);
    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trgl;
    cout << (*ppoly1).area() << endl;
    cout << (*ppoly2).area() << endl;
    (*ppoly1).nonVirtualFunc();
    (*ppoly2).nonVirtualFunc();

    return 0;
}

// Expect:
//
// 25
// 12.5
// Calling Polygon::nonVirtualFunc
// Calling Polygon::nonVirtualFunc
//
// 25
// 12.5
// Calling Polygon::nonVirtualFunc
// Calling Polygon::nonVirtualFunc
//
// 25
// 12.5
// Calling Polygon::nonVirtualFunc
// Calling Polygon::nonVirtualFunc


