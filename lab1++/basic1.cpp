#include <iostream>

int main() {
    int a;
    int b;
    // ввод текста в консоль
    std::cout << "Введите целые значения a и b: " << std::endl;
    if (!(std::cin >> a >> b)) {
        std::cout << "Ошибка: нужно ввести целые числа" << std::endl;
        return 1;
    }
    // проверка деления на ноль
    if (b == 0) {
        std::cout << "Второе число не должно быть нулем" << std::endl;
    } 
    // если b не равно нулю, выполняется условие
    else {
        int remainder = a % b;
        std::cout << "Остаток от деления " << a << " на " << b << " = " << remainder << std::endl;
    }

    return 0;
}