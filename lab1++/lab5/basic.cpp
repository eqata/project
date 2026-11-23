#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const double eps = 1e-9; // маленькое число для учета погрешности double
    double a, b, h;

    // проверяем ввод через while, чтобы отловить буквы и неверные границы
    while (true) {
        std::cout << "Введите a, b, h: ";
        std::cin >> a >> b >> h;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // очищаем буфер если ввели не число
            std::cout << "Ошибка: нужно вводить числа" << std::endl;
            continue;
        }

        if (a > b || h <= 0) {
            std::cout << "Ошибка: должно быть a <= b и h > 0" << std::endl;
            continue;
        }
        break;
    }

    // шапка таблицы
    std::cout << "+----------+---------------+" << std::endl;
    std::cout << "|    x     |   y = 5 / x   |" << std::endl;
    std::cout << "+----------+---------------+" << std::endl;

    std::cout << std::fixed << std::setprecision(4);

    // цикл for пишем b + eps вместо b, потому что double хранится с микропогрешностью
    for (double x = a; x <= b + eps; x += h) {
        // проверяем деление на ноль
        if (std::fabs(x) < eps) {
            std::cout << "| " << std::setw(8) << 0.0 << " | не определено |" << std::endl;
            continue; 
        }

        double y = 5.0 / x; // считаем функцию
        std::cout << "| " << std::setw(8) << x << " | " << std::setw(13) << y << " |" << std::endl;
    }

    std::cout << "+----------+---------------+" << std::endl;

    return 0;
}