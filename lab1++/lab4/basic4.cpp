#include <iostream>

int main() {
    int color;

    std::cout << "Введите код цвета (1-4): ";
    std::cin >> color;

    switch (color) {
        case 1: // ввод 1
            std::cout << "Красный" << std::endl;
            break;
        case 2: //ввод 2
            std::cout << "Зелёный" << std::endl;
            break;
        case 3: //ввод 3
            std::cout << "Синий" << std::endl;
            break;
        case 4: //ввод 4
            std::cout << "Жёлтый" << std::endl;
            break;
        default: // любое другое число
            std::cout << "Ошибка: введите число от 1 до 4!" << std::endl;
            break;
    }

    return 0;
}