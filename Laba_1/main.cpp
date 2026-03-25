/**
 * ============================================================
 *  Лабораторна робота №1
 *  Тема: Вступ до основ ООП та C++
 *  Мета: Ознайомитися з базовими принципами ООП (інкапсуляція,
 *        успадкування, поліморфізм), основами синтаксису C++,
 *        створити першу просту програму з використанням класів
 *        та об'єктів.
 * ============================================================
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>

constexpr double kPi = 3.14159265358979323846;

// ─────────────────────────────────────────────────────────
//  Допоміжна функція — роздільник для читабельного виводу
// ─────────────────────────────────────────────────────────
void printSeparator(const std::string& title = "")
{
    std::cout << "\n" << std::string(56, '=') << "\n";
    if (!title.empty())
        std::cout << "  " << title << "\n" << std::string(56, '-') << "\n";
}

// ─────────────────────────────────────────────────────────
//  ЧАСТИНА 1.  Демонстрація базового синтаксису C++
//              (змінні різних типів, ввід/вивід, функції)
// ─────────────────────────────────────────────────────────

/**
 * Проста функція, що повертає квадрат числа.
 * Демонструє оголошення та виклик функцій у C++.
 */
double square(double value)
{
    return value * value;
}

/**
 * Функція вітання — приймає ім'я і виводить повідомлення.
 */
void greet(const std::string& name)
{
    std::cout << "Привіт, " << name << "! Ласкаво просимо до C++.\n";
}

// ─────────────────────────────────────────────────────────
//  КЛАС: Point  —  точка на площині (x, y)
// ─────────────────────────────────────────────────────────
class Point
{
private:
    double x;   // абсциса (приховане поле)
    double y;   // ордината (приховане поле)

public:
    // --- Конструктори ---

    /** Конструктор за замовчуванням: точка в початку координат */
    Point() : x(0.0), y(0.0) {}

    /** Конструктор з параметрами */
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    // --- Методи доступу (гетери / сетери) ---

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // --- Обчислення відстані між двома точками ---
    double distanceTo(const Point& other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // --- Вивід координат ---
    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// ─────────────────────────────────────────────────────────
//  АБСТРАКТНИЙ БАЗОВИЙ КЛАС: Shape
//  Демонстрація успадкування та поліморфізму
// ─────────────────────────────────────────────────────────
class Shape
{
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
};

// ─────────────────────────────────────────────────────────
//  КЛАС: Circle  —  коло (радіус + центр-точка)
// ─────────────────────────────────────────────────────────
class Circle : public Shape
{
private:
    double radius;   // радіус (приховане поле)
    Point  center;   // центр (використовує клас Point)

public:
    // --- Конструктор з параметрами ---
    Circle(double r, double xCenter, double yCenter)
        : radius(r), center(xCenter, yCenter)
    {
        if (radius < 0.0) radius = 0.0;  // захист від некоректного значення
    }

    // --- Конструктор з точкою як центром ---
    Circle(double r, const Point& c)
        : radius(r), center(c)
    {
        if (radius < 0.0) radius = 0.0;
    }

    // --- Методи доступу ---
    double getRadius()      const { return radius; }
    Point  getCenter()      const { return center; }

    void setRadius(double r)          { if (r >= 0.0) radius = r; }
    void setCenter(double x, double y){ center.setX(x); center.setY(y); }
    void setCenter(const Point& p)    { center = p; }

    // --- Геометричні методи ---

    /** Площа кола: π·r² */
    double area() const override
    {
        return kPi * radius * radius;
    }

    /** Периметр (довжина кола): 2·π·r */
    double perimeter() const override
    {
        return 2.0 * kPi * radius;
    }

    /**
     * Визначає, чи перетинаються два кола.
     * Межі кіл мають спільну точку, якщо:
     * |r1-r2| <= dist(centers) <= r1+r2
     */
    bool intersects(const Circle& other) const
    {
        double dist = center.distanceTo(other.center);
        double radiiSum = radius + other.radius;
        double radiiDiff = std::fabs(radius - other.radius);
        return dist <= radiiSum && dist >= radiiDiff;
    }

    // --- Вивід ---
    void print() const override
    {
        std::cout << "Circle: center=";
        center.print();
        std::cout << ", radius=" << radius;
    }
};

// ─────────────────────────────────────────────────────────
//  КЛАС: Rectangle  —  прямокутник (ширина, висота, ліва верхня точка)
// ─────────────────────────────────────────────────────────
class Rectangle : public Shape
{
private:
    double width;    // ширина (приховане поле)
    double height;   // висота (приховане поле)
    Point  topLeft;  // ліва верхня вершина

public:
    // --- Конструктор за замовчуванням ---
    Rectangle() : width(0.0), height(0.0), topLeft(0.0, 0.0) {}

    // --- Конструктор з параметрами ---
    Rectangle(double w, double h, double x, double y)
        : width(w > 0 ? w : 0),
          height(h > 0 ? h : 0),
          topLeft(x, y)
    {}

    // --- Методи доступу ---
    double getWidth()   const { return width; }
    double getHeight()  const { return height; }
    Point  getTopLeft() const { return topLeft; }

    void setWidth(double w)  { if (w > 0) width  = w; }
    void setHeight(double h) { if (h > 0) height = h; }
    void setTopLeft(double x, double y) { topLeft.setX(x); topLeft.setY(y); }

    // --- Геометричні методи ---

    /** Площа прямокутника: w × h */
    double area() const override { return width * height; }

    /** Периметр прямокутника: 2·(w + h) */
    double perimeter() const override { return 2.0 * (width + height); }

    // --- Вивід ---
    void print() const override
    {
        std::cout << "Rectangle: topLeft=";
        topLeft.print();
        std::cout << ", width=" << width << ", height=" << height;
    }
};

// ─────────────────────────────────────────────────────────
//  ДОДАТКОВЕ ЗАВДАННЯ: Клас Triangle — трикутник
// ─────────────────────────────────────────────────────────
class Triangle : public Shape
{
private:
    Point a, b, c;  // три вершини (об'єкти класу Point)

public:
    Triangle(const Point& pA, const Point& pB, const Point& pC)
        : a(pA), b(pB), c(pC) {}

    /** Периметр: сума трьох сторін */
    double perimeter() const override
    {
        return a.distanceTo(b) + b.distanceTo(c) + c.distanceTo(a);
    }

    /** Площа за формулою Герона */
    double area() const override
    {
        double sideA = b.distanceTo(c);
        double sideB = a.distanceTo(c);
        double sideC = a.distanceTo(b);
        double s = (sideA + sideB + sideC) / 2.0; // напівпериметр
        double heron = s * (s - sideA) * (s - sideB) * (s - sideC);
        return heron > 0.0 ? std::sqrt(heron) : 0.0;
    }

    void print() const override
    {
        std::cout << "Triangle: A=";
        a.print();
        std::cout << ", B=";
        b.print();
        std::cout << ", C=";
        c.print();
    }
};

void printShapeMetrics(const Shape& shape, const std::string& label)
{
    std::cout << label << ":\n  ";
    shape.print();
    std::cout << "\n  Площа     : " << shape.area() << "\n";
    std::cout << "  Периметр  : " << shape.perimeter() << "\n";
}

// ─────────────────────────────────────────────────────────
//  ГОЛОВНА ФУНКЦІЯ
// ─────────────────────────────────────────────────────────
int main()
{
    // Встановлюємо точність виводу дійсних чисел
    std::cout << std::fixed << std::setprecision(4);

    // ── РОЗДІЛ 1: Базовий синтаксис C++ ──────────────────
    printSeparator("РОЗДІЛ 1: Базовий синтаксис C++");

    // Змінні різних типів
    int    age    = 20;
    double height = 175.5;
    char   grade  = 'A';
    bool   passed = true;
    std::string name = "Студент";

    std::cout << "Ім'я    : " << name   << "\n";
    std::cout << "Вік     : " << age    << " років\n";
    std::cout << "Зріст   : " << height << " см\n";
    std::cout << "Оцінка  : " << grade  << "\n";
    std::cout << "Здав?   : " << (passed ? "Так" : "Ні") << "\n";

    // Демонстрація вводу через std::cin
    std::cout << "\nВведіть ваше ім'я: ";
    std::string userName;
    std::getline(std::cin >> std::ws, userName);
    if (!userName.empty()) {
        name = userName;
    }

    std::cout << "Введіть число для піднесення до квадрата: ";
    double valueForSquare = 7.0;
    if (!(std::cin >> valueForSquare)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        valueForSquare = 7.0;
        std::cout << "Некоректний ввід. Використано значення за замовчуванням: 7.0000\n";
    }

    // Виклик простих функцій
    greet(name);
    std::cout << "Квадрат числа " << valueForSquare
              << " = " << square(valueForSquare) << "\n";

    // ── РОЗДІЛ 2: Клас Point ──────────────────────────────
    printSeparator("РОЗДІЛ 2: Клас Point");

    Point p1;               // конструктор за замовчуванням
    Point p2(3.0, 4.0);     // конструктор з параметрами

    std::cout << "p1 = "; p1.print(); std::cout << "\n";
    std::cout << "p2 = "; p2.print(); std::cout << "\n";

    // Зміна координат через сетери (інкапсуляція)
    p1.setX(1.0);
    p1.setY(1.0);
    std::cout << "p1 після setX/setY: "; p1.print(); std::cout << "\n";

    double dist = p1.distanceTo(p2);
    std::cout << "Відстань між p1 та p2: " << dist << "\n";

    // ── РОЗДІЛ 3: Клас Circle ─────────────────────────────
    printSeparator("РОЗДІЛ 3: Клас Circle");

    Circle c1(5.0, 0.0, 0.0);
    c1.print();
    std::cout << "\n";
    std::cout << "  Площа     : " << c1.area()      << "\n";
    std::cout << "  Периметр  : " << c1.perimeter() << "\n";

    // Змінюємо радіус і центр через сетери
    c1.setRadius(10.0);
    c1.setCenter(2.0, 3.0);
    std::cout << "\nПісля зміни:\n  ";
    c1.print();
    std::cout << "\n";
    std::cout << "  Площа     : " << c1.area()      << "\n";
    std::cout << "  Периметр  : " << c1.perimeter() << "\n";

    // Перевірка перетину двох кіл
    Circle c2(4.0, 8.0, 0.0);
    Circle c3(2.0, 30.0, 30.0);

    std::cout << "\nc1: "; c1.print(); std::cout << "\n";
    std::cout << "c2: "; c2.print(); std::cout << "\n";
    std::cout << "c3: "; c3.print(); std::cout << "\n";

    std::cout << "\nc1 перетинається з c2? "
              << (c1.intersects(c2) ? "Так" : "Ні") << "\n";
    std::cout << "c1 перетинається з c3? "
              << (c1.intersects(c3) ? "Так" : "Ні") << "\n";

    // ── РОЗДІЛ 4: Клас Rectangle ──────────────────────────
    printSeparator("РОЗДІЛ 4: Клас Rectangle");

    Rectangle r1(8.0, 5.0, 0.0, 0.0);
    r1.print();
    std::cout << "\n";
    std::cout << "  Площа     : " << r1.area()      << "\n";
    std::cout << "  Периметр  : " << r1.perimeter() << "\n";

    // Зміна параметрів
    r1.setWidth(12.0);
    r1.setHeight(7.5);
    r1.setTopLeft(1.0, -2.0);
    std::cout << "\nПісля зміни:\n  ";
    r1.print();
    std::cout << "\n";
    std::cout << "  Площа     : " << r1.area()      << "\n";
    std::cout << "  Периметр  : " << r1.perimeter() << "\n";

    // ── РОЗДІЛ 5 (Додатковий): Клас Triangle ─────────────
    printSeparator("РОЗДІЛ 5 (Додатково): Клас Triangle");

    Point tA(0.0, 0.0);
    Point tB(4.0, 0.0);
    Point tC(0.0, 3.0);

    Triangle tri(tA, tB, tC);
    tri.print();
    std::cout << "\n";
    std::cout << "  Периметр  : " << tri.perimeter() << "\n";
    std::cout << "  Площа     : " << tri.area()      << "\n";

    //          Єгипетський трикутник 3-4-5
    std::cout << "\nПеревірка правила 3-4-5 (прямокутний трикутник):\n";
    std::cout << "  Очікувана площа = 6.0000, отримана = "
              << tri.area() << "\n";

    // ── РОЗДІЛ 6: Успадкування і поліморфізм ─────────────
    printSeparator("РОЗДІЛ 6: Успадкування і поліморфізм");

    std::vector<const Shape*> shapes = { &c1, &r1, &tri };
    std::vector<std::string> labels = {
        "Circle як Shape",
        "Rectangle як Shape",
        "Triangle як Shape"
    };

    for (std::size_t i = 0; i < shapes.size(); ++i) {
        printShapeMetrics(*shapes[i], labels[i]);
        if (i + 1 != shapes.size()) {
            std::cout << "\n";
        }
    }

    // ── Завершення ────────────────────────────────────────
    printSeparator();
    std::cout << "  Програму виконано успішно.\n";
    std::cout << std::string(56, '=') << "\n\n";

    return 0;
}
