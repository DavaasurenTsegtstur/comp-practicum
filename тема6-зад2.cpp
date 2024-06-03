#include <iostream>
#include <cmath>
#include <vector>

// Функция для вычисления значения f(x1, x2)
double f(double x1, double x2) {
    return x1 + 2*x2 + 4*sqrt(1 + x1*x1 + x2*x2);
}

// Функция для вычисления градиента функции f
std::vector<double> gradient(double x1, double x2) {
    double sqrt_term = sqrt(1 + x1*x1 + x2*x2);
    double df_dx1 = 1 + 4 * (x1 / sqrt_term);
    double df_dx2 = 2 + 4 * (x2 / sqrt_term);
    return {df_dx1, df_dx2};
}

// Метод наискорейшего спуска
void gradientDescent(double alpha, int max_iter, double tol) {
    double x1 = 0.0, x2 = 0.0; // Начальные значения
    for (int i = 0; i < max_iter; ++i) {
        std::vector<double> grad = gradient(x1, x2);
        double grad_norm = sqrt(grad[0]*grad[0] + grad[1]*grad[1]);
        
        // Проверка критерия остановки
        if (grad_norm < tol) {
            std::cout << "Converged in " << i << " iterations." << std::endl;
            break;
        }
        
        // Обновление значений переменных
        x1 -= alpha * grad[0];
        x2 -= alpha * grad[1];
        
        // Вывод текущих значений
        std::cout << "Iteration " << i+1 << ": x1 = " << x1 << ", x2 = " << x2 << ", f(x) = " << f(x1, x2) << std::endl;
    }
    std::cout << "Optimized values: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    std::cout << "Minimum value of function: f(x) = " << f(x1, x2) << std::endl;
}

int main() {
    double alpha = 0.01;  // Шаг обучения
    int max_iter = 1000;  // Максимальное количество итераций
    double tol = 1e-6;    // Допустимая погрешность
    
    gradientDescent(alpha, max_iter, tol);
    
    return 0;
}
