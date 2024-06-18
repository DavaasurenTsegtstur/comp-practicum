import random
import sympy as sp

# Генерация случайных параметров гиперболического цилиндра
a = random.uniform(1, 10)
b = random.uniform(1, 10)

# Генерация случайных параметров плоскости
A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)

# Генерация случайных параметров прямой
x0 = random.uniform(-20, 20)
y0 = random.uniform(-20, 20)
z0 = random.uniform(-20, 20)
dx = random.uniform(-10, 10)
dy = random.uniform(-10, 10)
dz = random.uniform(-10, 10)

# Генерация случайной точки
x_point = random.uniform(-20, 20)
y_point = random.uniform(-20, 20)
z_point = random.uniform(-20, 20)

# Проверка принадлежности точки гиперболическому цилиндру
def is_point_on_hyperbolic_cylinder(a, b, x, y):
    return (x**2 / a**2 - y**2 / b**2) == 1

point_belongs = is_point_on_hyperbolic_cylinder(a, b, x_point, y_point)

# Проверка пересечения плоскости с гиперболическим цилиндром
def does_plane_intersect_cylinder(a, b, A, B, C, D):
    x, y = sp.symbols('x y')
    eq1 = x**2 / a**2 - y**2 / b**2 - 1
    z = sp.solve(A*x + B*y + C*z + D, z)[0]
    eq2 = eq1.subs('z', z)
    return sp.solve(eq2, (x, y))

plane_intersects = bool(does_plane_intersect_cylinder(a, b, A, B, C, D))

# Проверка пересечения прямой с гиперболическим цилиндром
def does_line_intersect_cylinder(a, b, x0, y0, z0, dx, dy, dz):
    t = sp.symbols('t')
    x = x0 + t * dx
    y = y0 + t * dy
    eq = x**2 / a**2 - y**2 / b**2 - 1
    solutions = sp.solve(eq, t)
    return len(solutions) > 0

line_intersects = does_line_intersect_cylinder(a, b, x0, y0, z0, dx, dy, dz)

# Вывод результатов
print(f"Параметры гиперболического цилиндра: a = {a:.2f}, b = {b:.2f}")
print(f"Параметры плоскости: A = {A:.2f}, B = {B:.2f}, C = {C:.2f}, D = {D:.2f}")
print(f"Параметры прямой: точка ({x0:.2f}, {y0:.2f}, {z0:.2f}), направление ({dx:.2f}, {dy:.2f}, {dz:.2f})")
print(f"Точка: ({x_point:.2f}, {y_point:.2f}, {z_point:.2f})")
print(f"Принадлежит ли точка гиперболическому цилиндру? {'Да' if point_belongs else 'Нет'}")
print(f"Пересекает ли плоскость гиперболический цилиндр? {'Да' if plane_intersects else 'Нет'}")
print(f"Пересекает ли прямая гиперболический цилиндр? {'Да' if line_intersects else 'Нет'}")
