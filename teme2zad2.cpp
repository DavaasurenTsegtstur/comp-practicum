#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Структура для представления трехмерного вектора
struct Vector3D {
    double x, y, z;
};

// Функция для вычисления длины вектора
double vectorLength(const Vector3D& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Функция для вычисления скалярного произведения двух векторов
double dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Функция для вычисления угла между двумя векторами
double angleBetweenVectors(const Vector3D& v1, const Vector3D& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = vectorLength(v1);
    double len2 = vectorLength(v2);
    return acos(dot / (len1 * len2));
}

// Функция для нахождения суммы двух векторов
Vector3D addVectors(const Vector3D& v1, const Vector3D& v2) {
    return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

// Функция для нахождения разности двух векторов
Vector3D subtractVectors(const Vector3D& v1, const Vector3D& v2) {
    return { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

// Функция для проверки параллельности двух векторов
bool areParallel(const Vector3D& v1, const Vector3D& v2) {
    double cross_x = v1.y * v2.z - v1.z * v2.y;
    double cross_y = v1.z * v2.x - v1.x * v2.z;
    double cross_z = v1.x * v2.y - v1.y * v2.x;
    return (cross_x == 0 && cross_y == 0 && cross_z == 0);
}

// Функция для проверки того, что векторы не лежат в одной плоскости
bool areNotCoplanar(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
    double volume = v1.x * (v2.y * v3.z - v2.z * v3.y) -
                    v1.y * (v2.x * v3.z - v2.z * v3.x) +
                    v1.z * (v2.x * v3.y - v2.y * v3.x);
    return volume != 0;
}

int main() {
    srand(time(0));

    // Генерация случайных векторов
    Vector3D v1 = { rand() % 100, rand() % 100, rand() % 100 };
    Vector3D v2 = { rand() % 100, rand() % 100, rand() % 100 };
    Vector3D v3 = { rand() % 100, rand() % 100, rand() % 100 };

    // Вывод векторов
    std::cout << "Vector 1: (" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";
    std::cout << "Vector 2: (" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";
    std::cout << "Vector 3: (" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";

    // Вычисление и вывод длин векторов
    std::cout << "Length of Vector 1: " << vectorLength(v1) << "\n";
    std::cout << "Length of Vector 2: " << vectorLength(v2) << "\n";
    std::cout << "Length of Vector 3: " << vectorLength(v3) << "\n";

    // Вычисление и вывод углов между векторами
    std::cout << "Angle between Vector 1 and Vector 2: " << angleBetweenVectors(v1, v2) << " radians\n";
    std::cout << "Angle between Vector 1 and Vector 3: " << angleBetweenVectors(v1, v3) << " radians\n";
    std::cout << "Angle between Vector 2 and Vector 3: " << angleBetweenVectors(v2, v3) << " radians\n";

    // Вычисление и вывод суммы векторов
    Vector3D sum12 = addVectors(v1, v2);
    Vector3D sum13 = addVectors(v1, v3);
    Vector3D sum23 = addVectors(v2, v3);
    std::cout << "Sum of Vector 1 and Vector 2: (" << sum12.x << ", " << sum12.y << ", " << sum12.z << ")\n";
    std::cout << "Sum of Vector 1 and Vector 3: (" << sum13.x << ", " << sum13.y << ", " << sum13.z << ")\n";
    std::cout << "Sum of Vector 2 and Vector 3: (" << sum23.x << ", " << sum23.y << ", " << sum23.z << ")\n";

    // Вычисление и вывод разности векторов
    Vector3D diff12 = subtractVectors(v1, v2);
    Vector3D diff13 = subtractVectors(v1, v3);
    Vector3D diff23 = subtractVectors(v2, v3);
    std::cout << "Difference of Vector 1 and Vector 2: (" << diff12.x << ", " << diff12.y << ", " << diff12.z << ")\n";
    std::cout << "Difference of Vector 1 and Vector 3: (" << diff13.x << ", " << diff13.y << ", " << diff13.z << ")\n";
    std::cout << "Difference of Vector 2 and Vector 3: (" << diff23.x << ", " << diff23.y << ", " << diff23.z << ")\n";

    // Проверка параллельности векторов
    std::cout << "Are Vector 1 and Vector 2 parallel? " << (areParallel(v1, v2) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 1 and Vector 3 parallel? " << (areParallel(v1, v3) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 2 and Vector 3 parallel? " << (areParallel(v2, v3) ? "Yes" : "No") << "\n";

    // Проверка того, что векторы не лежат в одной плоскости
    std::cout << "Are vectors not coplanar? " << (areNotCoplanar(v1, v2, v3) ? "Yes" : "No") << "\n";

    return 0;
}
