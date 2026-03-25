#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    void draw() const override { std::cout << "Circle(r=" << r << ")"; }
    double area() const override { return 3.14159265 * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    void draw() const override { std::cout << "Rectangle(" << w << "x" << h << ")"; }
    double area() const override { return w * h; }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    void draw() const override { std::cout << "Triangle(" << a << "," << b << "," << c << ")"; }
    double area() const override {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    std::vector<Shape*> shapes = {new Circle(5), new Rectangle(4, 6), new Triangle(3, 4, 5)};
    for (auto* s : shapes) {
        s->draw();
        std::cout << " area=" << s->area() << "\n";
        delete s;
    }
    return 0;
}
