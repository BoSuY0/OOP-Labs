#include <iostream>

class Complex {
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    Complex operator+(const Complex& o) const { return {re + o.re, im + o.im}; }
    Complex operator-(const Complex& o) const { return {re - o.re, im - o.im}; }
    Complex operator*(const Complex& o) const {
        return {re * o.re - im * o.im, re * o.im + im * o.re};
    }
    Complex operator/(const Complex& o) const {
        double d = o.re * o.re + o.im * o.im;
        return {(re * o.re + im * o.im) / d, (im * o.re - re * o.im) / d};
    }
    bool operator==(const Complex& o) const { return re == o.re && im == o.im; }
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.re << (c.im >= 0 ? "+" : "") << c.im << "i";
        return os;
    }
};

int main() {
    Complex a(3, 2), b(1, -1);
    std::cout << "a = " << a << "\nb = " << b << "\n";
    std::cout << "a+b = " << (a + b) << "\n";
    std::cout << "a-b = " << (a - b) << "\n";
    std::cout << "a*b = " << (a * b) << "\n";
    std::cout << "a/b = " << (a / b) << "\n";
    std::cout << "a==b: " << (a == b ? "true" : "false") << "\n";
    std::cout << "a==a: " << (a == a ? "true" : "false") << "\n";
    return 0;
}
