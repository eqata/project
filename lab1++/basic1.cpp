#include <iostream>

int main() {
    int a;
    int b;

    std::cout << "Введите число a: ";
    std::cin >> a;

    std::cout << "Введите число b: ";
    std::cin >> b;

    if (b == 0) {
        std::cout << "ошибка: на ноль делить нельзя" << std::endl;
        return 1;
    }

    int ost = a % b;

    std::cout << "остаток от деления " << a << " на " << b
              << " = " << ost << std::endl;

    return 0;
}
