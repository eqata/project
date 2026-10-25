#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    int year;

    std::cout << "Введите год: ";
    std::cin >> year;

// защита от ввода букв или отрицательного года
    if (std::cin.fail() || year <= 0) {
        std::cout << "Ошибка: введите корректный положительный год" << std::endl;
    } 
    else {
            // проверка условия високосного года
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            std::cout << year << " - високосный год" << std::endl;
        } else {
            std::cout << year << " - невисокосный год" << std::endl;
        }
    }

    return 0;
}