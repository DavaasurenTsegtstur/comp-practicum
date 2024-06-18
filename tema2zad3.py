import random
import math

# Функция для проверки, принадлежит ли точка гиперболе
def is_point_on_hyperbola(a, b, x, y):
    return (x**2 / a**2 - y**2 / b**2) == 1

# Функция для нахождения координат фокусов гиперболы
def foci_of_hyperbola(a, b):
    c = math.sqrt(a**2 + b**2)
    return ((c, 0), (-c, 0))

# Функция для нахождения эксцентриситета гиперболы
def eccentricity_of_hyperbola(a, b):
    return math.sqrt(1 + (b**2 / a**2))

# Функция для нахождения расстояния между директрисами гиперболы
def distance_between_directrices(a, b):
    return 2 * a**2 / math.sqrt(a**2 + b**2)

# Генерация случайных параметров гиперболы
a = random.uniform(1, 10)
b = random.uniform(1, 10)

# Генерация случайной точки
x = random.uniform(-20, 20)
y = random.uniform(-20, 20)

# Проверка, принадлежит ли точка гиперболе
belongs = is_point_on_hyperbola(a, b, x, y)

# Нахождение координат фокусов гиперболы
foci = foci_of_hyperbola(a, b)

# Нахождение эксцентриситета гиперболы
eccentricity = eccentricity_of_hyperbola(a, b)

# Нахождение расстояния между директрисами гиперболы
directrices_distance = distance_between_directrices(a, b)

# Вывод результатов
print(f"Параметры гиперболы: a = {a:.2f}, b = {b:.2f}")
print(f"Точка: ({x:.2f}, {y:.2f})")
print(f"Принадлежит ли точка гиперболе? {'Да' if belongs else 'Нет'}")
print(f"Координаты фокусов гиперболы: {foci}")
print(f"Длина действительной полуоси (a): {a:.2f}")
print(f"Длина мнимой полуоси (b): {b:.2f}")
print(f"Эксцентриситет гиперболы: {eccentricity:.2f}")
print(f"Расстояние между директрисами гиперболы: {directrices_distance:.2f}")
