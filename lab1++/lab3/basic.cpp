#include <iostream>

int main() {

    setlocale(LC_ALL, "Russian");

    double number;

    std::cout << "Введите число: ";
    std::cin >> number;

// проверяем, не ввел ли пользователь буквы вместо цифр
    if (std::cin.fail()) {
        std::cout << "Некорректный ввод" << std::endl;
    } 
// если число больше нуля, считаем его квадрат
    else if (number > 0) {
        double result = number * number;
        std::cout << "Квадрат числа: " << result << std::endl;
    } 

    else {
        std::cout << "Некорректный ввод" << std::endl;
    }

    return 0;
}