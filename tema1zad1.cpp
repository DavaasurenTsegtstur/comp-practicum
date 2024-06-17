#include <iostream>
using namespace std;

class Complex {
public:
    double real; // Действительная часть
    double imag; // Мнимая часть

    Complex() {
        real = imag = 0;
    }

    // Сложение комплексных чисел
    Complex add(const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    // Вычитание комплексных чисел
    Complex subtract(const Complex& other) {
        Complex result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    // Умножение комплексных чисел
    Complex multiply(const Complex& other) {
        Complex result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag + imag * other.real;
        return result;
    }

    // Деление комплексных чисел
    Complex divide(const Complex& other) {
        Complex result;
        double denominator = other.real * other.real + other.imag * other.imag;
        result.real = (real * other.real + imag * other.imag) / denominator;
        result.imag = (imag * other.real - real * other.imag) / denominator;
        return result;
    }
};

int main() {
    Complex z1, z2;
    cout << "Введите действительную часть для z1: ";
    cin >> z1.real;
    cout << "Введите мнимую часть для z1: ";
    cin >> z1.imag;

    cout << "Введите действительную часть для z2: ";
    cin >> z2.real;
    cout << "Введите мнимую часть для z2: ";
    cin >> z2.imag;

    Complex sum = z1.add(z2);
    Complex difference = z1.subtract(z2);
    Complex product = z1.multiply(z2);
    Complex quotient = z1.divide(z2);

    cout << "Сумма: " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "Разность: " << difference.real << " + " << difference.imag << "i" << endl;
    cout << "Произведение: " << product.real << " + " << product.imag << "i" << endl;
    cout << "Частное: " << quotient.real << " + " << quotient.imag << "i" << endl;

    return 0;
}
