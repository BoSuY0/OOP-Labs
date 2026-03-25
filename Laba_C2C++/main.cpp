#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    double x;

    std::cout << "Введіть розмірність масиву n (наприклад, 7): ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Помилка: n має бути більшим за 0." << std::endl;
        return 1;
    }

    std::cout << "Введіть значення x (наприклад, 0.8): ";
    std::cin >> x;

    std::vector<double> A(n);

    double partial_sum = 0.0;
    double fact_prod = 1.0;

    for (int k = 1; k <= n; ++k) {
        fact_prod *= k;
        double angle = std::fmod(fact_prod * x, 2 * M_PI);
        double term = std::sin(k * x) * std::cos(angle);
        
        if (k % 2 == 0) {
            term = -term;
        }
        
        partial_sum += term;
        A[k - 1] = partial_sum;
    }

    // Виправляємо помилку С-коду: 
    // Ініціалізація min_val ПІСЛЯ заповнення масиву
    int min_pos = 1;
    double min_val = A[0];

    for (int i = 1; i < n; ++i) {
        if (A[i] < min_val) {
            min_val = A[i];
            min_pos = i + 1;
        }
    }

    std::cout << "Порядковий номер найменшого елемента: " << min_pos << "\n";
    
    // Встановлення точність без <iomanip>
    std::cout.precision(10);
    std::cout << "Значення мінімального елемента: " << std::fixed << min_val << "\n";

    return 0;
}
