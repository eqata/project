#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const double eps = 1e-9; // точность для сравнения double
    double a, b, h;

    // ввод интервала с проверкой на ошибки
    while (true) {
        std::cout << "Введите a, b, h: ";
        std::cin >> a >> b >> h;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // чистим буфер от букв
            std::cout << "Ошибка: нужно вводить числа" << std::endl;
            continue;
        }

        if (a > b || h <= 0) {
            std::cout << "Ошибка: должно быть a <= b и h > 0" << std::endl;
            continue;
        }
        break;
    }

    double result = 1.0; // аккумулятор для произведения, начинаем с 1 чтобы не обнулить все
    bool zero = false; // флаг, встретился ли ноль среди значений y

    // шапка таблицы
    std::cout << "+----------+---------------+" << std::endl;
    std::cout << "|    x     |  y = |x| - 5  |" << std::endl;
    std::cout << "+----------+---------------+" << std::endl;

    std::cout << std::fixed << std::setprecision(4);

    // табуляция через for пишем b + eps вместо b, потому что double хранится с микропогрешностью
    for (double x = a; x <= b + eps; x += h) {
        // убираем -0.0000 если x попал в ноль с погрешностью
        if (std::fabs(x) < eps) {
            x = 0.0;
        }

        double y = std::fabs(x) - 5.0; // вычисляем значение функции

        // проверяем значение функции на ноль
        if (std::fabs(y) < eps) {
            y = 0.0;
            zero = true;
        } else {
            result *= y; // умножаем в аккумулятор
        }

        std::cout << "| " << std::setw(8) << x << " | " << std::setw(13) << y << " |" << std::endl;
    }

    std::cout << "+----------+---------------+" << std::endl;

    // вывод результата
    if (zero) {
        std::cout << "Среди значений есть 0, общее произведение = 0.0000" << std::endl;
        std::cout << "Произведение без учета нулей = " << result << std::endl;
    } else {
        std::cout << "Произведение значений = " << result << std::endl;
    }

    return 0;
}