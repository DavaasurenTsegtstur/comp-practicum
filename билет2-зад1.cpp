#include <iostream>
#include <cmath>

double f(double x1, double x2) {
    return x1 + 5 * x2 + exp(x1 * x1 + x2 * x2);
}

int main() {
    double x1 = 0.0; // Начальная точка
    double x2 = 0.0;
    double alpha = 0.01; // Размер шага

    for (int k = 0; k < 100; ++k) { // Максимальное количество итераций
        double df_dx1 = 1 + 2 * x1 * exp(x1 * x1 + x2 * x2);
        double df_dx2 = 5 + 2 * x2 * exp(x1 * x1 + x2 * x2);

        x1 -= alpha * df_dx1;
        x2 -= alpha * df_dx2;
    }

    double optimal_value = f(x1, x2);
    std::cout << "Optimal value: " << optimal_value << std::endl;

    return 0;
}
