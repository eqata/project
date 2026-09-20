#include <iostream>
#include <limits>

int main() {
    int days;

    std::cout << "Введите количество дней: ";
    std::cin >> days;

    // проверка правильности ввода
    if (std::cin.fail()) {
        std::cout << "Ошибка: нужно ввести целое число." << std::endl;

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        return 1;
    }

    // проверка отрицательного значения
    if (days < 0) {
        std::cout << "Ошибка: количество дней не может быть отрицательным." << std::endl;
        return 1;
    }

    const int daysinmonth = 30;
    const int daysinyear = 360;

    // считаем количество полных лет
    int years = days / daysinyear;

    // находим оставшиеся дни после лет
    int remainingdays = days % daysinyear;

    // считаем количество полных месяцев
    int months = remainingdays / daysinmonth;

    // находим оставшиеся дни
    int remaining = remainingdays % daysinmonth;

    // вывод результата
    std::cout << "Результат:" << std::endl;
    std::cout << "Годы: " << years << std::endl;
    std::cout << "Месяцы: " << months << std::endl;
    std::cout << "Дни: " << remaining << std::endl;

    return 0;
}
