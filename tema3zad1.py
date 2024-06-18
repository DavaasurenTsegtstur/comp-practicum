import numpy as np

# Функция для интегрирования
def f(x):
    return x**4 / (11 + x**2)

# Метод прямоугольников
def rectangle_method(f, a, b, n):
    h = (b - a) / n
    integral_left = sum(f(a + i * h) for i in range(n)) * h
    integral_right = sum(f(a + (i + 1) * h) for i in range(n)) * h
    return integral_left, integral_right

# Метод трапеций
def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    integral = 0.5 * (f(a) + f(b)) + sum(f(a + i * h) for i in range(1, n))
    return integral * h

# Метод Симпсона
def simpson_method(f, a, b, n):
    if n % 2 == 1:
        n += 1  # Симпсонов метод требует четного числа интервалов
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n):
        if i % 2 == 0:
            integral += 2 * f(a + i * h)
        else:
            integral += 4 * f(a + i * h)
    return integral * h / 3

# Параметры интеграла
a, b = 1, 2
n = 1000000  # Количество разбиений

# Вычисления
rect_left, rect_right = rectangle_method(f, a, b, n)
trapezoidal = trapezoidal_method(f, a, b, n)
simpson = simpson_method(f, a, b, n)

# Вывод результатов
print(f"Метод прямоугольников (левый): {rect_left:.6f}")
print(f"Метод прямоугольников (правый): {rect_right:.6f}")
print(f"Метод трапеций: {trapezoidal:.6f}")
print(f"Метод Симпсона: {simpson:.6f}")
