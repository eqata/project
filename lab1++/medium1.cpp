#include <iostream>
#include <iomanip>

int main() {
    int mark1, mark2, mark3;

    std::cout << "Введите первую оценку: ";
    // проверка на дробное число
    if (!(std::cin >> mark1) || std::cin.peek() == '.') {
        std::cout << "Ошибка: введено дробное число или буквы." << std::endl;
        return 1;
    }

    std::cout << "Введите вторую оценку: ";
    if (!(std::cin >> mark2) || std::cin.peek() == '.') {
        std::cout << "Ошибка: введено дробное число или буквы." << std::endl;
        return 1;
    }

    std::cout << "Введите третью оценку: ";
    if (!(std::cin >> mark3) || std::cin.peek() == '.') {
        std::cout << "Ошибка: введено дробное число или буквы." << std::endl;
        return 1;
    }

    // проверяем диапазон оценки.
    if (mark1 < 0 || mark1 > 5 ||
        mark2 < 0 || mark2 > 5 ||
        mark3 < 0 || mark3 > 5) {
        std::cout << "Ошибка: оценки должны быть от 0 до 5." << std::endl;
        return 1;
    }

    // вычисление среднего балла
    double result = (mark1 + mark2 + mark3) / 3.0;

    // настройка вывода и вывод
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Средний балл: " << result << std::endl;

    return 0;
    }