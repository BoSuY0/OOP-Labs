/*
 * Лабораторна робота №1
 * Тема: Вступ до основ ООП та C++
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

constexpr double PI = 3.14159265;

// Базовий клас — абстрактна фігура
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
};

// Коло
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override { return PI * radius * radius; }
    double perimeter() const override { return 2 * PI * radius; }

    void print() const override {
        std::cout << "Circle(r=" << radius
                  << "): S=" << area()
                  << ", P=" << perimeter() << "\n";
    }
};

// Прямокутник
class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    double area() const override { return w * h; }
    double perimeter() const override { return 2 * (w + h); }

    void print() const override {
        std::cout << "Rectangle(" << w << "x" << h
                  << "): S=" << area()
                  << ", P=" << perimeter() << "\n";
    }
};

// Трикутник (за трьома сторонами, площа за формулою Герона)
class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() const override {
        double s = (a + b + c) / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }

    void print() const override {
        std::cout << "Triangle(" << a << "," << b << "," << c
                  << "): S=" << area()
                  << ", P=" << perimeter() << "\n";
    }
};

int main() {
    // Демонстрація поліморфізму
    Circle   circ(5.0);
    Rectangle rect(8.0, 5.0);
    Triangle  tri(3.0, 4.0, 5.0);

    std::vector<Shape*> shapes = {&circ, &rect, &tri};

    std::cout << "=== Фігури (поліморфізм) ===\n";
    for (auto* s : shapes)
        s->print();

    return 0;
}
