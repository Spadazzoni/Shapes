#include <cassert>
#include <iostream>
struct Point {
    double x;
    double y;
    Point(double a, double b) : x{a}, y{b} {assert(std::cin.good());}
   ~Point();
};
Point operator+(Point const& p, Point const& q) {
    return Point{p.x + q.x, p.y + q.y};
}
Point operator/(Point const& a, double div) {
    return Point{a.x / div, a.y / div};
}
struct Shape {
    Point p;
    Shape(Point p) : p{p} {}
    virtual ~Shape();
    virtual Point where() const {return p;} //le f virtuali pure possono essere definite?
};
struct Circle : Shape {
    double raggio;
    Circle(Point p, double b) : Shape{p}, raggio{b} {assert(std::cin.good());}
    ~Circle();
   // Point where() const override {return p;}
   //si può omettere dato che il metodo è ereditato dalla classe base
};
struct Rectangle : Shape {
    Point bassodx;
    Rectangle(Point p, Point down) : Shape{p}, bassodx{down} {assert(std::cin.good());}
    ~Rectangle();
    Point where() const override {return (Shape::where() + bassodx)/2;} //shapes::where restituisce p, ovvero il valore del punto in alto a destra del rettangolo
};
/*int main()
{
    double a;
    double b;
    std::cin >> a >> b;
    Point c{a,b};
}*/