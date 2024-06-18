#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Структура для представления вектора
struct Vector {
    double x, y;
};

// Функция для вычисления длины вектора
double vectorLength(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Функция для вычисления скалярного произведения двух векторов
double dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// Функция для вычисления угла между двумя векторами
double angleBetweenVectors(const Vector& v1, const Vector& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = vectorLength(v1);
    double len2 = vectorLength(v2);
    return acos(dot / (len1 * len2));
}

// Функция для нахождения суммы двух векторов
Vector addVectors(const Vector& v1, const Vector& v2) {
    return { v1.x + v2.x, v1.y + v2.y };
}

// Функция для нахождения разности двух векторов
Vector subtractVectors(const Vector& v1, const Vector& v2) {
    return { v1.x - v2.x, v1.y - v2.y };
}

// Функция для проверки параллельности двух векторов
bool areParallel(const Vector& v1, const Vector& v2) {
    return (v1.x * v2.y == v1.y * v2.x);
}

int main() {
    srand(time(0));
    
    // Генерация случайных векторов
    Vector v1 = { rand() % 100, rand() % 100 };
    Vector v2 = { rand() % 100, rand() % 100 };
    Vector v3 = { rand() % 100, rand() % 100 };
    
    // Вывод векторов
    std::cout << "Vector 1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Vector 2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "Vector 3: (" << v3.x << ", " << v3.y << ")\n";
    
    // Вычисление и вывод длин векторов
    std::cout << "Length of Vector 1: " << vectorLength(v1) << "\n";
    std::cout << "Length of Vector 2: " << vectorLength(v2) << "\n";
    std::cout << "Length of Vector 3: " << vectorLength(v3) << "\n";
    
    // Вычисление и вывод углов между векторами
    std::cout << "Angle between Vector 1 and Vector 2: " << angleBetweenVectors(v1, v2) << " radians\n";
    std::cout << "Angle between Vector 1 and Vector 3: " << angleBetweenVectors(v1, v3) << " radians\n";
    std::cout << "Angle between Vector 2 and Vector 3: " << angleBetweenVectors(v2, v3) << " radians\n";
    
    // Вычисление и вывод суммы векторов
    Vector sum12 = addVectors(v1, v2);
    Vector sum13 = addVectors(v1, v3);
    Vector sum23 = addVectors(v2, v3);
    std::cout << "Sum of Vector 1 and Vector 2: (" << sum12.x << ", " << sum12.y << ")\n";
    std::cout << "Sum of Vector 1 and Vector 3: (" << sum13.x << ", " << sum13.y << ")\n";
    std::cout << "Sum of Vector 2 and Vector 3: (" << sum23.x << ", " << sum23.y << ")\n";
    
    // Вычисление и вывод разности векторов
    Vector diff12 = subtractVectors(v1, v2);
    Vector diff13 = subtractVectors(v1, v3);
    Vector diff23 = subtractVectors(v2, v3);
    std::cout << "Difference of Vector 1 and Vector 2: (" << diff12.x << ", " << diff12.y << ")\n";
    std::cout << "Difference of Vector 1 and Vector 3: (" << diff13.x << ", " << diff13.y << ")\n";
    std::cout << "Difference of Vector 2 and Vector 3: (" << diff23.x << ", " << diff23.y << ")\n";
    
    // Проверка параллельности векторов
    std::cout << "Are Vector 1 and Vector 2 parallel? " << (areParallel(v1, v2) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 1 and Vector 3 parallel? " << (areParallel(v1, v3) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 2 and Vector 3 parallel? " << (areParallel(v2, v3) ? "Yes" : "No") << "\n";

    return 0;
}
