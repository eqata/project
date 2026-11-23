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
            std::cin.ignore(10000, '\n'); // очищаем буфер при неверном вводе
            std::cout << "Ошибка: нужно вводить числа" << std::endl;
            continue;
        }

        if (a > b || h <= 0) {
            std::cout << "Ошибка: должно быть a <= b и h > 0" << std::endl;
            continue;
        }
        break;
    }

    // шапка таблицы берем функцию y = 1 / (x^2 - 1)
    std::cout << "+----------+---------------+" << std::endl;
    std::cout << "|    x     | y = 1/(x^2-1) |" << std::endl;
    std::cout << "+----------+---------------+" << std::endl;

    std::cout << std::fixed << std::setprecision(4);

    for (double x = a; x <= b + eps; x += h) {
        if (std::fabs(x) < eps) {
            x = 0.0;
        }

        double den = x * x - 1.0; // отдельно считаем знаменатель для проверки

        // если знаменатель равен 0, значит в этой точке разрыв
        if (std::fabs(den) < eps) {
            std::cout << "| " << std::setw(8) << x << " |        разрыв |" << std::endl;
            continue; // пропускаем деление на ноль
        }

        double y = 1.0 / den; // считаем функцию
        std::cout << "| " << std::setw(8) << x << " | " << std::setw(13) << y << " |" << std::endl;
    }

    std::cout << "+----------+---------------+" << std::endl;

    return 0;
}