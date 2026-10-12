#include <iostream>

int main() {

// объявляем переменные типа int
    int a;
    int b;
    int ostatok;

    std::cout << "Введите первое целое число (a): ";
    std::cin >> a;

    std::cout << "Введите второе целое число (b): ";
    std::cin >> b;

// считаем остаток через процент
    ostatok = a % b;

// выводим ответ на экран
    std::cout << "Остаток от деления " << a << " на " << b << " равен " << ostatok << std::endl;

    return 0;
}
